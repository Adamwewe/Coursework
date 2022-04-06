-- Like operator:
	-- very useful to look for strings
-- SQL full text helps with spelling and natural language search

-- Select all columns
SELECT *
FROM film
-- Select only records that begin with the word 'GOLD'
WHERE title LIKE 'GOLD%';

SELECT *
FROM film
-- Select only records that end with the word 'GOLD'
WHERE title LIKE '%GOLD';

SELECT *
FROM film
-- Select only records that contain the word 'GOLD'
WHERE title LIKE '%GOLD%';

-- ts vector and tsquery:

/*
You saw how to convert strings to tsvector and tsquery in the video 
and, in this exercise, we are going to dive deeper into what these 
functions actually return after converting a string to a 
tsvector. In this example, you will convert a text column from 
the film table to a tsvector and inspect the results. 
Understanding how full-text search works is the first step in 
more advanced machine learning and data science concepts like 
natural language processing.

*/

-- In other words, it is the equivalent of BOW representation

-- Select the film description as a tsvector

SELECT to_tsvector(description)
FROM film;


-- when combining the above with word searches, the matching
-- operator needs to be used such as '@@'

-- Select the title and description
SELECT title, description
FROM film
-- Convert the title to a tsvector and match it against the tsquery 
WHERE to_tsvector(title) @@ to_tsquery('elf');

-- You can also enumerate:

/*
ENUM or enumerated data types are great options to use in your 
database when you have a column where you want to store a fixed
list of values that rarely change. 
Examples of when it would be appropriate to use an ENUM include
days of the week and states or provinces in a country.

Another example can be the directions on a compass 
(i.e., north, south, east and west.) 
In this exercise, you are going to create a new ENUM 
data type called compass_position.

*/

-- Create an enumerated data type, compass_position
CREATE TYPE compass_position AS ENUM (
  	-- Use the four cardinal directions
  	'North', 
  	'South',
  	'East', 
  	'West'
);
-- Confirm the new data type is in the pg_type system table
SELECT typname
FROM pg_type
WHERE typname='compass_position';


--

/*
The Sakila database has a user-defined enum data type 
called mpaa_rating. The rating column in the film table is 
an mpaa_rating type and contains the familiar rating for that 
film like PG or R. This is a great example of when an enumerated
 data type comes in handy. Film ratings have a limited number of
 standard values that rarely change.

When you want to learn about a column or data type in your database the best place to start is the INFORMATION_SCHEMA. You can find information about the rating column that can help you learn about the type of data you can expect to find. For enum data types, you can also find the specific values that are valid for a particular enum by looking in the pg_enum system table. Let's dive into the exercises and learn more.
*/


-- Select the column name, data type and udt name columns

-- Select the column name, data type and udt name columns
SELECT column_name, data_type, udt_name
FROM INFORMATION_SCHEMA.COLUMNS 
-- Filter by the rating column in the film table
WHERE table_name ='film' AND column_name='rating';

SELECT *
FROM pg_type 
WHERE typname='mpaa_rating'


-- How functions work:
	-- below, predefined custom methods are called:
	
	
/*
you were running a real-life DVD Rental store, there are many
 questions that you may need to answer repeatedly like whether 
 a film is in stock at a particular store or the outstanding 
 balance for a particular customer. These types of scenarios 
 are where user-defined functions will come in very handy. 
 The Sakila database has several user-defined functions 
 pre-defined. These functions are available out-of-the-box and 
 can be used in your queries like many of the built-in functions
 we've learned about in this course.

In this exercise, you will build a query step-by-step that can 
be used to produce a report to determine which film title is 
currently held by which customer using the inventory_held_by_customer() 
function.

*/


-- Select the film title, rental and inventory ids
SELECT 
	f.title, 
    i.inventory_id,
    -- Determine whether the inventory is held by a customer
    inventory_held_by_customer(i.inventory_id) AS held_by_cust
FROM film as f 
	-- Join the film table to the inventory table
	INNER JOIN inventory AS i ON f.film_id=i.film_id;
	
	
-- Select the film title and inventory ids
SELECT 
	f.title, 
    i.inventory_id,
    -- Determine whether the inventory is held by a customer
    inventory_held_by_customer(i.inventory_id) as held_by_cust
FROM film as f 
	INNER JOIN inventory AS i ON f.film_id=i.film_id 
WHERE
	-- Only include results where the held_by_cust is not null
    inventory_held_by_customer(i.inventory_id) IS NOT NULL;
    

-- PostgreSQL also comes with many extensions:
	-- to find out which ones are possible do:
		-- pg_avalable_extensions 
		-- or
		-- pg_extension

-- Select all rows extensions
SELECT *
FROM pg_available_extensions;

-- Enabling the pg_trgm extension
CREATE EXTENSION IF NOT EXISTS pg_trgm;

-- example of an extension at work similarity()


-- Select the title and description columns
SELECT 
  title, 
  description, 
  -- Calculate the similarity
  similarity(title,description)
FROM 
  film
  
  
 -- Select the title and description columns
SELECT  
  title, 
  description, 
  -- Calculate the levenshtein distance
  levenshtein(title,'JET NEIGHBOR') AS distance
FROM 
  film
ORDER BY 3



-- Select the title and description columns
SELECT  
  title, 
  description 
FROM 
  film
WHERE 
  -- Match "Astounding Drama" in the description
  to_tsvector(description) @@ 
  to_tsquery('Astounding & Drama');
  
  
 
SELECT 
  title, 
  description, 
  -- Calculate the similarity
  similarity(description, 'Astounding & Drama')
FROM 
  film 
WHERE 
  to_tsvector(description) @@ 
  to_tsquery('Astounding & Drama') 
ORDER BY 
	similarity(description, 'Astounding & Drama') DESC;
	
	
	

  
 


  

	
	
