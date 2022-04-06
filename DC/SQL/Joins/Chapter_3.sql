-- Select fields
SELECT code, year
  -- From economies
  FROM economies
	-- Set theory clause
	UNION ALL
-- Select fields
SELECT country_code, year
  -- From populations
  FROM populations
-- Order by code, year
ORDER BY code, year;

/*
Standard Union drops all duplicates
Union All keeps all duplicates
*/

-- Intersection in action (pretty self-explanatory):

-- Select fields
SELECT name
  -- From countries
 FROM countries
	-- Set theory clause
	INTERSECT
-- Select fields
SELECT name
  -- From cities
  FROM cities;


-- EXCEPT: When you need to extract unique values depoending on a key, i.e:
	-- values in a key that do not appear in the foreign key
	
-- Select field
SELECT name
  -- From cities
  FROM cities
	-- Set theory clause
	EXCEPT 
-- Select field
SELECT capital
  -- From countries
  FROM countries
-- Order by result
ORDER BY name;

-- one more doinhg the opposite:

-- Select field
SELECT capital
  -- From countries
  FROM countries
	-- Set theory clause
	EXCEPT
-- Select field
SELECT name
  -- From cities
  FROM cities
  
-- Order by ascending capital
ORDER BY capital;


-- We saw the data-adding joins so far,
	-- now we will see the anti-joins and semi-joins to filter data depending on the values
	-- of the second table
	
	-- Semi-join: use the left table to match the records by key fields on the left 
	-- Anti-join: //	//			to retrieve the different records!!!!
	
	
	-- Query from step 2
SELECT DISTINCT name
  FROM languages
-- Where in statement
WHERE code IN
  -- Query from step 1
  -- Subquery
  (SELECT code
   FROM countries
   WHERE region = 'Middle East')
-- Order by name
ORDER BY name;



-- Another example of the anti-join:


-- Select fields
SELECT code, name, region
  -- From Countries
  FROM countries 
  -- Where continent is Oceania
  WHERE continent = 'Oceania'
  	-- And code not in
  	AND code NOT IN
  	-- Subquery
  	(SELECT code
  	 FROM currencies);
	 
-- Challenge question:

-- Select the city name
SELECT name
  -- Alias the table where city name resides
  FROM cities AS c1
  -- Choose only records matching the result of multiple set theory clauses
  WHERE country_code IN
(
    -- Select appropriate field from economies AS e
    SELECT e.code
    FROM economies AS e
    -- Get all additional (unique) values of the field from currencies AS c2   
    UNION
    SELECT c2.code
    FROM currencies AS c2
    -- Exclude those appearing in populations AS p  
    EXCEPT
    SELECT p.country_code
    FROM populations AS p
);