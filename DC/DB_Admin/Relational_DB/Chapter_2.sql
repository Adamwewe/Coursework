"""
Date style settings can be restricted as can be seen below:
"""

-- Let's add a record to the table
INSERT INTO transactions (transaction_date, amount, fee) 
VALUES ('09/24/2018', 5454, '30');

-- Doublecheck the contents
SELECT *
FROM transactions;

"""
Type casting can be changed:
"""

-- Calculate the net amount as amount + fee
SELECT transaction_date , amount + CAST(fee AS INTEGER) AS net_amount
FROM transactions;



"""
more type casting
"""

-- Select the university_shortname column
SELECT DISTINCT(university_shortname)  
FROM professors;

-- Specify the correct fixed-length character type
ALTER TABLE professors
ALTER COLUMN university_shortname
TYPE VARCHAR(3);

-- Change the type of firstname
ALTER TABLE professors
ALTER COLUMN firstname
TYPE VARCHAR(64);

-- Convert the values in firstname to a max. of 16 characters
ALTER TABLE professors 
ALTER COLUMN firstname 
TYPE varchar(16)
USING SUBSTRING (firstname FROM 1 FOR 16);

-- NON null constraints:

-- Disallow NULL values in firstname
ALTER TABLE professors 
ALTER COLUMN firstname SET NOT NULL;

-- Disallow NULL values in lastname
ALTER TABLE professors
ALTER COLUMN lastname SET NOT NULL;

-- Other Custom constraints:

-- Make universities.university_shortname unique
ALTER TABLE universities
ADD CONSTRAINT university_shortname_unq UNIQUE(university_shortname);

