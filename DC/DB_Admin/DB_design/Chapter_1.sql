-- OLTP vs OLAP
	-- OLTP --> Transactions
	-- OLAP --> Online analytics 
	
-- Structured Data vs Unstructured vs Semi-structured:
	-- Structured --> follows a schema and defined data types 
	-- Unstructured --> no Schemas, represents most of the world
	-- Semi-structured --> self-describig, no larger schema is followed (example schemas: JSON)

-- DW vs DB vs DL:
	--DB:
		-- OLTP only 
	-- DW:
		-- Optimized for analytics
		-- Organized for read/aggregating data
		-- Usually read only
		-- Multiple sources used
		-- Massive Parallelization
	-- DL:
		-- Stores all types of data at a lower cost
			-- unstructured mainly
		-- Petabytes
		-- Schema-on-read instead of schema-on-write
		-- Needs a catalogue
	

-- Storing data:
	-- ETL
		-- Extract --> Transform --> Load
		-- Mainly warehouse 
	
	-- ELT:
		-- Extract --> Load --> Transform
		-- Mainly DL 

-- Look into recording for fact and dimension tables in more detail

-- How it works with some simple examples:

	-- Create a route dimension table
	
CREATE TABLE route(
	route_id INTEGER PRIMARY KEY,
    park_name VARCHAR(160) NOT NULL,
    city_name VARCHAR(160) NOT NULL,
    distance_km FLOAT NOT NULL,
    route_name VARCHAR(160) NOT NULL
);
-- Create a week dimension table
CREATE TABLE week(
	week_id INTEGER PRIMARY KEY,
    week INTEGER NOT NULL,
    month VARCHAR(160) NOT NULL,
    year INTEGER NOT NULL
);

SELECT 
	-- Select the sum of the duration of all runs
	SUM(duration_mins)
FROM 
	runs_fact;

SELECT 
	-- Get the total duration of all runs
	SUM(duration_mins)
FROM 
	runs_fact
-- Get all the week_id's that are from July, 2019
INNER JOIN week_dim ON runs_fact.week_id = week_dim.week_id
WHERE month = 'July' and year = '2019';
	

