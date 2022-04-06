-- Creating roles, managing authorizations
	-- How to:
	
-- Create a data scientist role
CREATE ROLE data_scientist;

-- Create a role for Marta
CREATE ROLE marta WITH LOGIN;

-- Create an admin role
CREATE ROLE admin WITH CREATEDB CREATEROLE;

-- Grant data_scientist update and insert privileges
GRANT UPDATE, INSERT ON long_reviews TO data_scientist;

-- Give Marta's role a password
ALTER ROLE marta WITH PASSWORD 's3cur3p@ssw0rd';


-- Add Marta to the data scientist group
GRANT data_scientist TO Marta;

-- Remove Marta from the data scientist group
REVOKE data_scientist FROM Marta;


-- Data partitioning: split table into smaller parts to make queries faster


-- Create a new table called film_descriptions
CREATE TABLE film_descriptions (
    film_id INT,
    long_description TEXT
);

-- Copy the descriptions from the film table
INSERT INTO film_descriptions
SELECT film_id, long_description FROM film;
    
-- Drop the descriptions from the original table
ALTER TABLE film DROP COLUMN long_description;

-- Join to view the original table
SELECT * FROM film_descriptions
JOIN film USING(film_id);

-- Doing partitioning 

-- Create a new table called film_partitioned
CREATE TABLE film_partitioned (
  film_id INT,
  title TEXT NOT NULL,
  release_year TEXT
)

PARTITION BY LIST (release_year);

-- Create the partitions for 2019, 2018, and 2017
CREATE TABLE film_2019
	PARTITION OF film_partitioned FOR VALUES IN ('2019');
    
CREATE TABLE film_2018
	PARTITION OF film_partitioned FOR VALUES IN ('2018');
    
CREATE TABLE film_2017
	PARTITION OF film_partitioned FOR VALUES IN ('2017');
	
-- Insert the data into film_partitioned
INSERT INTO film_partitioned
SELECT film_id, title, release_year FROM film;

-- View film_partitioned
SELECT * FROM film_partitioned;

-- Data Integration:
	-- Importance of transformations/data integration tools to make a unified data model
	
-- DBMS:
	-- Software for creating and maintaining databases
	-- Comes in two types:
		-- SQL
			-- Based on relational management system
			-- Best when data is structured
		-- NOSQL
			-- Less structured
			-- Doc-centered
			-- NoSQL is best:
				-- rapid growth 
				-- no clear schema definitions
				-- large quantities of data 

				
				
				
				
		