-- Keys vs SuperKeys:
-- Count the number of rows in universities
SELECT COUNT(universities) 
FROM universities;

-- Count the number of distinct values in the university_city column
SELECT COUNT(DISTINCT(university_city)) 
FROM universities;


-- Identifying candidate keys in 2 steps:



--    - Count the distinct records for all possible combinations of columns. 
--	 If the resulting number x equals the number of all rows in the table for a 
--	 combination, you have discovered a superkey.

--    - Then remove one column after another until you can no longer remove columns 
--	 without seeing the number x decrease. If that is the case, you have discovered a 
--	 (candidate) key.

-- DO NOT FORGET TO TRY DIFFERENT COLUMN COMBINATIONS

-- Try out different combinations
SELECT COUNT(DISTINCT(firstname, lastname)) 
FROM professors;


-- More primary keys:

-- Rename the organization column to id
ALTER TABLE organizations
RENAME COLUMN organization TO id;

-- Make id a primary key
ALTER TABLE organizations
ADD CONSTRAINT organization_pk PRIMARY KEY (id);

-- Rename the university_shortname column to id
ALTER TABLE universities
RENAME COLUMN university_shortname TO id;

-- Make id a primary key
ALTER TABLE universities
ADD CONSTRAINT university_pk PRIMARY KEY (id);


-- Surrogate keys:
	-- != primary keys bc they are artifcial unlike primary keys
	-- also added as a column first then you do the constrainting work

-- Add the new column to the table
ALTER TABLE professors 
ADD COLUMN id serial;

-- Make id a primary key
ALTER TABLE professors 
ADD CONSTRAINT professors_pkey PRIMARY KEY (id);

-- Have a look at the first 10 rows of professors
SELECT *
FROM professors
LIMIT 10;


-- Now all the above from scratch:

-- Count the number of distinct rows with columns make, model
SELECT COUNT(DISTINCT(make, model)) 
FROM cars;

-- Add the id column
ALTER TABLE cars
ADD COLUMN id varchar(128);

-- Update id with make + model
UPDATE cars
SET id = CONCAT(make, model);

-- Make id a primary key
ALTER TABLE cars
ADD CONSTRAINT id_pk PRIMARY KEY(id);

-- Have a look at the table
SELECT * FROM cars;

-- Now from scratch 

-- Create the table
CREATE TABLE students (
  last_name VARCHAR(128) NOT NULL,
  ssn INTEGER PRIMARY KEY,
  phone_no CHAR(12)
);


