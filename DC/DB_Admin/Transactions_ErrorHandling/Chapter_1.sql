-- Error handling, no intro needed you know how it works

-- Set up the TRY block
BEGIN TRY
	-- Add the constraint
	ALTER TABLE products
		ADD CONSTRAINT CHK_Stock CHECK (stock >= 0);
END TRY
-- Set up the CATCH block
BEGIN CATCH 
	SELECT 'An error occurred!';
END CATCH 

-- Some convoluted nested try/catch blocks:

-- Set up the first TRY block
BEGIN TRY
	INSERT INTO buyers (first_name, last_name, email, phone)
		VALUES ('Peter', 'Thompson', 'peterthomson@mail.com', '555000100');
END TRY

-- Set up the first CATCH block
BEGIN CATCH 
	SELECT 'An error occurred inserting the buyer! You are in the first CATCH block';
    -- Set up the nested TRY block
    BEGIN TRY
    	INSERT INTO errors 
        	VALUES ('Error inserting a buyer');
        SELECT 'Error inserted correctly!';
	END TRY
    -- Set up the nested CATCH block
    BEGIN CATCH
    	SELECT 'An error occurred inserting the error! You are in the nested CATCH block';
    END CATCH
END CATCH

-- Error codes:
	-- ranges from 1 to 49999
	-- own custom errors are from 50001 up
	
	-- Here is the full outline:
		-- 0-10: informational messages
		-- 11-16: errors that are user-corrected (constraint violation)
		-- 17-24: Other errors (software pbs, fatal errors)
		
		
-- Some errors are uncatchable:
	-- When severety is lower than 11 --> Catch will not works
	-- Severety of 20 and higher stop connection, if not stopped then error is thrown
	-- compilation errors are also not caught
	

BEGIN TRY
	INSERT INTO products (product_name, stock, price)
		VALUES ('Sun Bicycles ElectroLite - 2017', 10, 1559.99);
END TRY
BEGIN CATCH
	SELECT 'An error occurred inserting the product!';
    BEGIN TRY
    	INSERT INTO errors
        	VALUES ('Error inserting a product');
    END TRY    
    BEGIN CATCH
    	SELECT 'An error occurred inserting the error!';
    END CATCH    
END CATCH

-- Predefined message functions

-- Set up the TRY block
BEGIN TRY 	
	SELECT 'Total: ' + SUM(price * quantity) AS total
	FROM orders  
END TRY
-- Set up the CATCH block
BEGIN CATCH   
	-- Show error information.
	SELECT  ERROR_NUMBER() AS number,  
         	ERROR_SEVERITY() AS severity_level,  
        	ERROR_STATE() AS state,
        	ERROR_LINE() AS line,  
        	ERROR_MESSAGE() AS message; 	
END CATCH



BEGIN TRY
    INSERT INTO products (product_name, stock, price) 
    VALUES	('Trek Powerfly 5 - 2018', 2, 3499.99),   		
    		('New Power K- 2018', 3, 1999.99)		
END TRY
-- Set up the outer CATCH block
BEGIN CATCH 
	SELECT 'An error occurred inserting the product!';
    -- Set up the inner TRY block
    BEGIN TRY
    	-- Insert the error
    	INSERT INTO errors 
        	VALUES ('Error inserting a product');
    end TRY
    -- Set up the inner CATCH block
    BEGIN CATCH 
    	-- Show number and message error
    	SELECT 
        	ERROR_LINE()AS line,	   
			ERROR_MESSAGE() AS message; 
    END CATCH
END CATCH 