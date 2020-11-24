-- Database Creation --
CREATE DATABASE Lincoln_Garden_Centre; 

USE Lincoln_Garden_Centre;
 -- Table Creation --
CREATE TABLE IF NOT EXISTS customer (
		Cust_Email varchar(255) UNIQUE, 
		Cust_Firstnm varchar(255) NOT NULL, 
		Cust_lastnm varchar(255) NOT NULL,
		Cust_Age int NOT NULL,
		House_Num int,
		Post_Code varchar (255) NOT NULL,
		Country varchar (255) DEFAULT 'England',
	PRIMARY KEY (Cust_Email),
	UNIQUE (Cust_Email)
); -- Used to store information on the Customer

CREATE TABLE IF NOT EXISTS address (
		Post_Code varchar(255) NOT NULL, 
		Street_Name varchar(255) NOT NULL, 
		City varchar(20) NOT NULL, 
		County varchar (255) NOT NULL, 
	PRIMARY KEY (Post_Code)
); -- Can be used to cross reference the persons postcode with the streetname

CREATE TABLE IF NOT EXISTS staff (
		Staff_Email varchar (255) NOT NULL, 
		Staff_Firstnm varchar (255) NOT NULL, 
		Staff_Lastnm varchar(30) NOT NULL, 
	PRIMARY KEY (Staff_Email),
	UNIQUE (Staff_Email)
); -- Information on the employees of the company

-- CREATE TABLE IF NOT EXISTS staff_qualifications (
		-- Staff_Email varchar (255) NOT NULL,
		-- Staff_Qualifications varchar (255) NOT NULL
	-- PRIMARY KEY (Staff_Email)
-- ); -- A table to contain all staff qualifications but was found to be too useless so was removed

CREATE TABLE IF NOT EXISTS item (
		Item_ID bigint NOT NULL AUTO_INCREMENT,
		Item_Name varchar(255) NOT NULL,  
		Item_Type varchar(255) NOT NULL, 
		Item_Descript varchar(2000) NOT NULL, 
		Item_Price float NOT NULL,
	PRIMARY KEY (Item_ID),
	UNIQUE (Item_ID),
	UNIQUE (Item_Name)
); -- Item information 

CREATE TABLE IF NOT EXISTS customer_order (
		Cust_Order_ID bigint NOT NULL,
		Cust_Email varchar(255) NOT NULL, 
		Cust_Order_Date date NOT NULL, 
		Item_ID bigint NOT NULL, 
		Quantity int NOT NULL,
		Discount int DEFAULT 0,
		Order_Total float (8,2)NOT NULL,
	PRIMARY KEY (Cust_Order_ID),
	CONSTRAINT Cust_Details FOREIGN KEY (Cust_Email) REFERENCES customer (Cust_Email)
		ON UPDATE CASCADE ON DELETE CASCADE,
	CONSTRAINT Item_Details FOREIGN KEY (Item_ID) REFERENCES item (Item_ID)
		ON UPDATE CASCADE ON DELETE CASCADE
	-- CONSTRAINT Check_Quant CHECK (Quantity > 0) -- In mysql Checks are ignored, will try to use a trigger instead
); -- Full customer orders, all details about purchase and person who purchased the items can be found using info here

-- Alter statements --
ALTER TABLE staff
	ADD Staff_Postcode varchar(255) NOT NULL
;

 -- ALTER TABLE staff 
	-- ADD CONSTRAINT Staff_Qual FOREIGN KEY (Staff_Email) REFERENCES staff_qualifications (Staff_Email) 
		-- ON UPDATE CASCADE ON DELETE CASCADE
 -- ; -- Altered after initial creation due to issues with foreign keys being linked to uncreated tables 

ALTER TABLE customer
	ADD CONSTRAINT addr FOREIGN KEY (Post_Code) REFERENCES address (Post_Code)
		ON UPDATE CASCADE ON DELETE CASCADE
;

ALTER TABLE customer_order 
	DROP COLUMN Discount
;
	
ALTER TABLE customer_order
	ADD Discount int
;
	
-- ALTER TABLE staff -- Causes issues with twin key constraints
	-- ADD CONSTRAINT Staff_Location FOREIGN KEY (Staff_Postcode) REFERENCES address (Post_Code)
		-- ON UPDATE CASCADE ON DELETE CASCADE
-- ;

-- Stored Procedures/Functions --
DELIMITER $$
CREATE TRIGGER Check_Quant BEFORE INSERT ON customer_order 
FOR EACH ROW 
	BEGIN 
		IF NEW.Quantity<0 THEN 
		SET NEW.Quantity=0; 
		END IF; 
	END
$$
DELIMITER ; -- Used in place of the CHECK statement for quantity as they do not function in MySQL

DELIMITER $$
CREATE FUNCTION It_Total(I_ID bigint, quan int, disc int)
RETURNS FLOAT
	BEGIN
		DECLARE Itot float;
		SET Itot = (quan  * (SELECT Item_Price FROM item WHERE item.Item_ID = I_ID LIMIT 1));
		SET Itot = Itot - (Itot * (disc / 100));
		RETURN Itot;
	END
$$
DELIMITER ; -- Used to calculate a singular order total

DELIMITER $$
CREATE FUNCTION Ord_Hist( Cu_Or_ID bigint)
RETURNS FLOAT
	BEGIN
		DECLARE Otot float;
		SET Otot = it_tot - (it_tot * disc);
		RETURN Otot;
	END
$$
DELIMITER ; -- Unused Function, was created to return a users whole order history but was not completed

DELIMITER //
CREATE PROCEDURE GetAllCustomers ()
	BEGIN
		SELECT * FROM customer;
	END
//
DELIMITER ; -- Used to return all data in the Customer table

DELIMITER //
CREATE PROCEDURE GetSeedItems ()
	BEGIN
		SELECT * FROM item WHERE item.Item_Type = 'Seeds' ;
	END
//
DELIMITER ; -- Used to return all items of item type seeds

-- DELIMITER $$ 
-- CREATE PROCEDURE Copy ( varchar(255) ol_Tab, varchar(255) new_Tab)
	-- BEGIN
		-- CREATE TABLE ol_Tab LIKE new_Tab; 
		-- INSERT ol_Tab SELECT * FROM new_Tab;
	-- END
-- $$
-- DELIMITER ; -- Failed Test, A field name can not be used as a table name without dynamic SQL

USE Lincoln_Garden_Centre; -- Was placed in middle of the code for error checking

-- INSERT Statements --
INSERT INTO address
		(Post_Code, Street_Name, City, County)
	VALUES
		('LN122QU', 'Bucknalls Meadow', 'Mabelthorpe', 'Lincolnshire'),
		('LN57WN', 'Firth Road', 'Lincoln', 'Lincolnshire'),
		('LN110ET', 'High Holme Road', 'Louth', 'Lincolnshire'),
		('LN119NB', 'Eastgate', 'Louth', 'Lincolnshire'),
		('LN119ER', 'Mercer Row', 'Louth', 'Lincolnshire'),
		('LN22WZ', 'Mill Rise', 'Lincoln', 'Lincolnshire'),
		('LN24QR', 'Bunkers Hill', 'Lincoln', 'Lincolnshire')
; 

INSERT INTO customer 
		(Cust_Email, Cust_Firstnm, Cust_lastnm, Cust_Age, House_Num, Post_Code, Country)
	VALUES 
		('John.Smith422@gmail.com', 'John', 'Smith', '42', '1', 'LN122QU', 'England'),
		('Georgie.Appleseed4@hotmail.com', 'Georgie', 'Appleseed', '20', '2000', 'LN57WN', 'England'),
		('Jacob92.Stevens@yahoo.com', 'Jacob', 'Stevens', '25', '3', 'LN110ET', 'England'),
		('Tom.Gearin666@gmail.com', 'Thomas', 'Gearin', '32', '12', 'LN119NB', 'England'),
		('Oliver.Const424@ntlworld.com', 'Oliver', 'Constantine', '75', '14', 'LN110ET', 'England')
;

INSERT INTO staff
		(Staff_Email, Staff_Firstnm, Staff_Lastnm, Staff_Postcode)
	VALUES	
		('StevenSmovdir@googlemail.com', 'Steven', 'Spielburg', 'LN24QR'),
		('Quentin@hotmail.com', 'Quentin', 'Tarantino', 'LN11QT'),
		('Guillermo.delt3@;live.com', 'Guillermo', 'del Toro', 'LN57AA')
;

-- INSERT INTO staff_qualifications
	--	(Staff_Email, Staff_Qualifications)
	-- VALUES
		-- ('StevenSmovdir@googlemail.com', 'Sales Training'),
		-- ('StevenSmovdir@googlemail.com', 'Cash Handling'),
		-- ('StevenSmovdir@googlemail.com', 'Assistant Manager Training'),
		-- ('Quentin@hotmail.com', 'Sales Training')
-- ;

INSERT INTO item
		(Item_Name, Item_Type, Item_Descript, Item_Price)
	VALUES
		('Brown Plant Pot', 'Outdoor Storage' , 'A brown flower pot used as storage', '5.99'),
		('Daffodil Seeds', 'Seeds', 'Seeds used for planting', '0.99' ),
		('Sunflower Seeds', 'Seeds', 'Seeds used for planting', '0.89' ),
		('Blue Plant Pot', 'Outdoor Storage' , 'A brlue flower pot used as storage', '6.00'),
		('Beetljuice BBQ 2000', 'Cooking' , 'Used to roast up a barbecue in the summer months', '299.99')
;

INSERT INTO customer_order
		(Cust_Order_ID, Cust_Email, Cust_Order_Date, Item_ID, Quantity, Discount, Order_Total)
	VALUES
		('1','John.Smith422@gmail.com', '2007-05-25', '1', '2', '0', It_Total(Item_ID, Quantity, Discount)),
		('2','Georgie.Appleseed4@hotmail.com', '2007-05-26', '2', '2', '20', It_Total(Item_ID, Quantity, Discount)),
		('3','Jacob92.Stevens@yahoo.com','2007-05-30',  '2', '1', '0', It_Total(Item_ID, Quantity, Discount))
;

-- UPDATE and DELETE statements --
UPDATE customer
	SET Cust_Age = '45'
	WHERE Cust_Email = 'John.Smith422@gmail.com'
;
UPDATE staff
	SET Staff_Firstnm = 'Stephen'
	WHERE Staff_Firstnm = 'Steven' AND Staff_lastnm = 'Spielburg'
;

DELETE FROM address
	WHERE Post_Code = 'LN22WZ'
;

-- SELECT/JOIN Statements --
SELECT customer.House_Num, address.Street_Name, address.City, address.County, customer.Post_Code
	FROM customer
	INNER JOIN address
		ON address.Post_Code = customer.Post_Code
; -- Displays all addresses used by customers

SELECT customer_order.Cust_Order_ID, customer.Cust_Firstnm, customer.Cust_lastnm, customer_order.Order_Total
	FROM customer 
	LEFT JOIN customer_order
		ON customer_order.Cust_Email =  customer.Cust_Email
	ORDER BY customer_order.Cust_Order_ID
; -- Displays Customer names and will show whether or not they have purchased anything, could be used for deleting old customer detials

SELECT customer_order.Cust_Order_ID, item.Item_ID, item.Item_Name
	FROM customer_order
	RIGHT JOIN item
		ON item.Item_ID = customer_order.Item_ID  
	ORDER BY item.Item_ID
; -- Displays all items and where in which orders they were sold, can be used to show which product is selling well

-- SELECT/UNION Statements --
SELECT Post_Code
	FROM customer
		UNION
SELECT Post_Code
	FROM address
; -- Displays all Postcodes used for customers, possible uses here include seeing whether all Postcodes are used effectively

-- Table Copies --
CREATE TABLE copy_of_customer LIKE customer; 
INSERT copy_of_customer SELECT * FROM customer;

CREATE TABLE copy_of_address LIKE address; 
INSERT copy_of_address SELECT * FROM address;

CREATE TABLE copy_of_staff LIKE staff; 
INSERT copy_of_staff SELECT * FROM staff;

-- CREATE TABLE copy_of_staff_qualifications LIKE staff_qualifications; 
-- INSERT copy_of_staff_qualifications SELECT * FROM staff_qualifications;

CREATE TABLE copy_of_item LIKE item; 
INSERT copy_of_item SELECT * FROM item;

CREATE TABLE copy_of_customer_order LIKE customer_order; 
INSERT copy_of_customer_order SELECT * FROM customer_order;

-- User Creations and Permissions --
CREATE USER 'user'@'%' IDENTIFIED BY 'Admin1_root'; -- Can also use local host instead of % but it is not as portable
GRANT SELECT, DROP ON *.* TO 'user'@'%';
REVOKE DROP ON *.* FROM 'user'@'%'; -- Was receiving errors for using REVOKE but when code was run it initialized correctly 
FLUSH PRIVILEGES;

-- Calling of a Procedure --
CALL GetAllCustomers();
CALL GetSeedItems();

-- Reset Code --
-- DROP DATABASE Lincoln_Garden_Centre;
-- DROP  USER 'user'@'%';