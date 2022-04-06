-- Very IMPORTANT: INDENTATION MATTERS HERE LIKE IN PYTHON
-- NOTE ON ALIASING, IT ONLY WORKS FOR VISUALIZING THE TABLE AND NOT WRITING THE ACTUAL 
-- CODE!!

-- Select name fields (with alias) and region 
-- ALSO IMPORTANT: when dealing with multiple tables, you need to put the table name before the column to select using a "."

SELECT cities.name AS city, countries.name AS country, countries.region 
FROM cities
  INNER JOIN countries
    ON city.country_code = countries.code;
	

-- Aliasing can also be done more efficiently for entire selections as such:
-- Even if an alias is declared further down in your script, the selection phase
-- also needs to be rewritten in the same fashion!!


-- Additionally put the names of the fields from the joining table in the selection phase as well!!



-- Select fields with aliases
SELECT c.code AS country_code, name, year, inflation_rate
FROM countries AS c
  -- Join to economies (alias e)
  INNER JOIN economies AS e
    -- Match on code
    ON c.code = e.code; -- IMPORTANT: when matching use the og name of the column but not the ne
	
	-- NOTE WHEN SELECTING IDENTICAL FIELDS FROM MULTIPLE SOURCES:
	
-- Note that year appears in both populations and economies, so you have to explicitly 
-- use e.year instead of year as you did before.


-- Joining with multiple conditions:

-- Select fields
SELECT c.code, name, region, e.year, fertility_rate, unemployment_rate
  -- From countries (alias as c)
  FROM countries AS c
  -- Join to populations (as p)
  INNER JOIN populations AS p
    -- Match on country code
    ON c.code = p.country_code
  -- Join to economies (as e)
  INNER JOIN economies AS e
    -- Match on country code and year
    ON c.code = e.code AND e.year = p.year;
	
-- The using shortcut:

-- Select fields
SELECT c.name AS country, continent, l.name AS languages, official
  -- From countries (alias as c)
  FROM countries AS c

  -- Join to languages (as l)
  INNER JOIN languages AS l
    -- Match using code
    USING(code)
	

-- Joining a table on itself:

-- Select fields with aliases
SELECT p1.country_code, p1.size AS size2010, p2.size AS size2015
-- From populations (alias as p1)
FROM populations AS p1
  -- Join to itself (alias as p2)
  INNER JOIN populations AS p2 -- once again, the secod table should be ignored until assingment
    -- Match on country code
    ON p1.country_code = p2.country_code
	
-- Performing small calculations on inner self joins

-- Select fields with aliases
SELECT p1.country_code,
       p1.size AS size2010,
       p2.size AS size2015
-- From populations (alias as p1)
FROM populations as p1
  -- Join to itself (alias as p2)
  INNER JOIN populations as p2
    -- Match on country code
    ON p1.country_code = p2.country_code AND p1.year = p2.year-5
        -- and year (with calculation)
     
-- More advanced calculations:

-- Select fields with aliases
SELECT p1.country_code,
       p1.size AS size2010, 
       p2.size AS size2015,
       -- Calculate growth_perc
       ((p2.size - p1.size)/p1.size * 100.0) AS growth_perc
-- From populations (alias as p1)
FROM populations AS p1
  -- Join to itself (alias as p2)
  INNER JOIN populations AS p2
    -- Match on country code
    ON p1.country_code = p2.country_code
        -- and year (with calculation)
        AND p1.year = p2.year - 5;
	
-- CASE WHEN, CASE THEN

SELECT name, continent, code, surface_area,
    -- First case
    CASE WHEN surface_area > 2000000 THEN 'large'
        -- Second case
        WHEN surface_area > 350000 THEN 'medium'
        -- Else clause + end
        ELSE 'small' END
        -- Alias name
        AS geosize_group
-- From table
FROM countries;


SELECT country_code, size,
    -- First case
    CASE WHEN size > 50000000 THEN 'large' 
        -- Second case
        WHEN size > 1000000 THEN 'medium'
        -- Else clause + end
        ELSE 'small' END
        -- Alias name (popsize_group)
        AS popsize_group
-- From table
FROM populations
-- Focus on 2015
WHERE year = 2015;

SELECT country_code, size,
  CASE WHEN size > 50000000
            THEN 'large'
       WHEN size > 1000000
            THEN 'medium'
       ELSE 'small' END
       AS popsize_group
INTO pop_plus       
FROM populations
WHERE year = 2015;

-- Select fields
SELECT name, continent, geosize_group, popsize_group
-- From countries_plus (alias as c)
FROM countries_plus AS c
  -- Join to pop_plus (alias as p)
  INNER JOIN pop_plus AS p
    -- Match on country code
    ON c.code = p.country_code
-- Order the table    
ORDER BY geosize_group;






