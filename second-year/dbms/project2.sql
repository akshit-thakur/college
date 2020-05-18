DESC client_master;
DESC product_master; 
DESC salesman_master;
DESC sales_order;
DESC sales_order_details;
DESC challan_header;
DESC challan_details;

SELECT * FROM client_master
SELECT * FROM product_master
SELECT * FROM salesman_master
SELECT * FROM sales_order
SELECT * FROM sales_order_details
SELECT * FROM challan_header
SELECT * FROM challan_details

CREATE TABLE client_master
(
    client_no varchar2(6) CONSTRAINT pk_cm PRIMARY KEY,
    name varchar2(20) NOT NULL,
    address1 varchar2(30),
    address2 varchar2(30),
    city varchar2(15),
    state varchar2(15),
    pincode number(6),
    bal_due number(10,2)
);


CREATE TABLE product_master
(
    product_no varchar2(6) CONSTRAINT pk_pm PRIMARY KEY,
    description varchar2(15) NOT NULL,
    profit_percent number(4,2) NOT NULL,
    unit_measure varchar2(10) NOT NULL,
    qty_on_hand number(8) NOT NULL,
    recorder_lvl number(8) NOT NULL,
    sell_price number(8,2) NOT NULL,
    cost_price number(8,2) NOT NULL
);

CREATE TABLE salesman_master
(
    salesman_no varchar2(6) CONSTRAINT pk_sm PRIMARY KEY,
    salesman_name varchar2(20) NOT NULL,
    address1 varchar2(30) NOT NULL,
    address2 varchar2(30),
    city varchar2(20),
    pincode number(6),
    state varchar2(20),
    sal_amt number(8,2) NOT NULL,
    tgt_to_get number(6,2) NOT NULL,
    ytd_sales number(6,2) NOT NULL,
    remarks varchar2(60)
);

CREATE TABLE sales_order
(
    s_order_no varchar2(6) CONSTRAINT pk_so PRIMARY KEY,
    s_order_date date,
    client_no varchar2(6),
    dely_addr varchar2(25),
    salesman_no varchar2(6),
    dely_type char(1) DEFAULT 'F',
    billed_yn char(1),
    dely_date date,
    order_status varchar2(10),
    CONSTRAINT fk_so_cm FOREIGN KEY(client_no) REFERENCES client_master(client_no) ON DELETE CASCADE,
    CONSTRAINT fk_so_sm FOREIGN KEY(salesman_no) REFERENCES salesman_master(salesman_no) ON DELETE CASCADE
);

CREATE TABLE sales_order_details
(
    s_order_no varchar2(6),
    product_no varchar2(6),
    qty_ordered number(8),
    qty_disp number(8),
    product_rate number(10,2),
    CONSTRAINT fk_sod_so FOREIGN KEY(s_order_no) REFERENCES sales_order(s_order_no) ON DELETE CASCADE,
    CONSTRAINT fk_sod_pm FOREIGN KEY(product_no) REFERENCES product_master(product_no) ON DELETE CASCADE,
    CONSTRAINT pk_sod PRIMARY KEY(s_order_no,product_no)
);

CREATE TABLE challan_header
(
    challan_no varchar2(6) CONSTRAINT pk_ch PRIMARY KEY,
    s_order_no varchar2(6),
    challan_date date NOT NULL,
    billed_yn char(1) DEFAULT 'N',
    CONSTRAINT fk_ch_so FOREIGN KEY(s_order_no) REFERENCES sales_order(s_order_no) ON DELETE CASCADE
);

CREATE TABLE challan_details
(
    challan_no varchar2(6),
    product_no varchar2(6),
    qty_disp number(4,2) NOT NULL,
    CONSTRAINT fk_cd_ch FOREIGN KEY(challan_no) REFERENCES challan_header(challan_no) ON DELETE CASCADE,
    CONSTRAINT fk_cd_pm FOREIGN KEY(product_no) REFERENCES product_master(product_no) ON DELETE CASCADE,
    CONSTRAINT pk_cd PRIMARY KEY(challan_no,product_no)
);

ALTER TABLE client_master 
ADD CONSTRAINT check_cnum CHECK(client_no like 'C%')

ALTER TABLE product_master 
ADD CONSTRAINT check_pnum CHECK(product_no like 'P%')

ALTER TABLE salesman_master 
ADD CONSTRAINT check_snum CHECK(salesman_no like 'S%')

ALTER TABLE sales_order 
ADD CONSTRAINT check_onum CHECK(s_order_no like 'O%')

ALTER TABLE product_master 
ADD CONSTRAINT check_sp CHECK(sell_price<>0)

ALTER TABLE product_master 
ADD CONSTRAINT check_cp CHECK(cost_price<>0)

ALTER TABLE salesman_master 
ADD CONSTRAINT check_sal CHECK(sal_amt<>0)

ALTER TABLE salesman_master 
ADD CONSTRAINT check_tgt CHECK(tgt_to_get<>0)

ALTER TABLE sales_order 
ADD CONSTRAINT type_val CHECK(dely_type IN('P','F'))

ALTER TABLE sales_order 
ADD CONSTRAINT status_val CHECK(order_status IN('In Process','Fulfilled','BackOrder','Canceled'))

ALTER TABLE sales_order 
ADD CONSTRAINT date_check CHECK(dely_date>s_order_date);

ALTER TABLE challan_header 
ADD CONSTRAINT billed_val CHECK(billed_yn IN('Y','N'))

ALTER TABLE challan_header 
ADD CONSTRAINT check_chnum CHECK(challan_no like 'CH%')

-- data entry

INSERT INTO client_master
VALUES
    ('C00001', 'Ivan Bayross', 'Bandra', '', 'Bombay', 'Maharashtra', '400054', '15000');

INSERT INTO client_master
VALUES
    ('C00002', 'Vandana Saitwal', '', '', 'Madras', 'Tamil Nadu', '780001', '0');
INSERT INTO client_master
VALUES
    ('C00003', 'Pramada Jaguste', 'Worli', '', 'Bombay', 'Maharashtra', '400057', '5000');

INSERT INTO client_master
VALUES
    ('C00004', 'Basu Navindgi', 'Dadar', '', 'Bombay', 'Maharashtra', '400056', '0');

INSERT INTO client_master
VALUES
    ('C00005', 'Ravi Sreedharan', 'Dwarka', '', 'Delhi', '', '100001', '2000');

INSERT INTO client_master
VALUES
    ('C00006', 'Rukmini', 'Andheri', '', 'Bombay', 'Maharashtra', '400050', '0');




INSERT INTO product_master
VALUES('P00001', '1.44 Floppies', '5', 'piece', '100', '20', '525', '500');

INSERT INTO product_master
VALUES('P03453', 'Monitors', '6', 'piece', '10', '3', '12000', '11280');

INSERT INTO product_master
VALUES('P06734', 'Mouse', '5', 'piece', '20', '5', '1050', '1000');

INSERT INTO product_master
VALUES('P07865', '1.22 Floppies', '5', 'piece', '100', '20', '525', '500');

INSERT INTO product_master
VALUES('P07868', 'Keyboards', '2', 'piece', '10', '3', '3150', '3050');

INSERT INTO product_master
VALUES('P07885', 'CD Drive', '2.5', 'piece', '10', '3', '3150', '3050');

INSERT INTO product_master
VALUES('P07965', '540 HDD', '4', 'piece', '10', '3', '5250', '5100');

INSERT INTO product_master
VALUES('P07975', '1.44 Drive', '5', 'piece', '10', '3', '1050', '1000');

INSERT INTO product_master
VALUES('P08865', '1.22 Drive', '5', 'piece', '2', '3', '1050', '1000');




INSERT INTO salesman_master
VALUES('S00001', 'Kiran', 'A/14', 'Worli', 'Bombay', '400002', 'MAH', '3000', '100', '50', 'Good');

INSERT INTO salesman_master
VALUES('S00002', 'Manish', '65', 'Nariman', 'Bombay', '400001', 'MAH', '3000', '200', '100', 'Good');

INSERT INTO salesman_master
VALUES('S00003', 'Ravi', 'P-7', 'Bandra', 'Bombay', '400032', 'MAH', '3000', '200', '100', 'Good');

INSERT INTO salesman_master
VALUES('S00004', 'Ashish', 'A/5', 'Juhu', 'Bombay', '400044', 'MAH', '3500', '200', '150', 'Good');



INSERT INTO sales_order
VALUES('O19001', '01/12/1996', 'C00001', '', 'S00001', 'F', 'N', '01/20/1996', 'In Process');

INSERT INTO sales_order
VALUES('O19002', '01/25/1996', 'C00002', '', 'S00002', 'P', 'N', '01/27/1996', 'Canceled');

INSERT INTO sales_order
VALUES('O46865', '02/18/1996', 'C00003', '', 'S00003', 'F', 'Y', '02/20/1996', 'Fulfilled');

INSERT INTO sales_order
VALUES('O19003', '04/03/1996', 'C00001', '', 'S00001', 'F', 'Y', '04/07/1996', 'Fulfilled');

INSERT INTO sales_order
VALUES('O46866', '05/20/1996', 'C00004', '', 'S00002', 'P', 'N', '05/22/1996', 'Canceled');

INSERT INTO sales_order
VALUES('O10008', '05/24/1996', 'C00005', '', 'S00004', 'F', 'N', '05/26/1996', 'In Process');


-- 18 09 2018

INSERT INTO sales_order_details
VALUES('O19001', 'P00001', 4, 4, 525);

INSERT INTO sales_order_details
VALUES('O19001', 'P07965', 2, 1, 8400);

INSERT INTO sales_order_details
VALUES('O19001', 'P07885', 2, 1, 5250);

INSERT INTO sales_order_details
VALUES('O19002', 'P00001', 10, 0, 525);

INSERT INTO sales_order_details
VALUES('O46865', 'P07868', 3, 3, 3150);

INSERT INTO sales_order_details
VALUES('O46865', 'P07885', 3, 1, 5250);

INSERT INTO sales_order_details
VALUES('O46865', 'P00001', 10, 10, 525);

INSERT INTO sales_order_details
VALUES('O46865', 'P03453', 4, 4, 1050);

INSERT INTO sales_order_details
VALUES('O19003', 'P03453', 2, 2, 1050);

INSERT INTO sales_order_details
VALUES('O19003', 'P06734', 1, 1, 12000);

INSERT INTO sales_order_details
VALUES('O46866', 'P07965', 1, 0, 8400);

INSERT INTO sales_order_details
VALUES('O46866', 'P07975', 1, 0, 1050);

INSERT INTO sales_order_details
VALUES('O10008', 'P00001', 10, 5, 525);

INSERT INTO sales_order_details
VALUES('O10008', 'P07975', 5, 3, 1050);


INSERT INTO challan_header
VALUES('CH9001', 'O19001', '12/12/1995', 'Y');

INSERT INTO challan_header
VALUES('CH6865', 'O46865', '11/12/1995', 'Y');

INSERT INTO challan_header
VALUES('CH3965', 'O10008', '10/12/1995', 'Y');






INSERT INTO challan_details
VALUES('CH9001', 'P00001', 4);

INSERT INTO challan_details
VALUES('CH9001', 'P07965', 1);

INSERT INTO challan_details
VALUES('CH9001', 'P07885', 1);

INSERT INTO challan_details
VALUES('CH6865', 'P07868', 3);

INSERT INTO challan_details
VALUES('CH6865', 'P03453', 4);

INSERT INTO challan_details
VALUES('CH6865', 'P00001', 10);

INSERT INTO challan_details
VALUES('CH3965', 'P00001', 5);

INSERT INTO challan_details
VALUES('CH3965', 'P07975', 2);


--queries 


--1. find name of all clients
SELECT distinct(name)
FROM client_master

--2. print info about all clients
SELECT *
FROM client_master

--3. list of names and cities of all clients
SELECT name, city
FROM client_master

--4. list various products available
SELECT distinct(description)
FROM product_master

--5. name of all clients having 'a' as second letter in their name
SELECT name
FROM client_master
WHERE name LIKE('_a%');

--6. clients staying in city whose second letter is 'a'
SELECT name, city
FROM client_master
WHERE city LIKE('_a%');

--7. clients who stay in delhi or madras or bombay
SELECT name, city
FROM client_master
WHERE city IN('Delhi','Madras','Bombay');

--8. clients who stay in bombay
SELECT name, city
FROM client_master
WHERE city = 'Bombay';

--9. clients whose bal due >=10k
SELECT name, bal_due
FROM client_master
WHERE bal_due >= 10000;

--10. order info for client_no c00001 and c00002
SELECT *
FROM sales_order
WHERE client_no IN('C00001','C00002');

--11. FIND PRODUCTS WITH DESC as 1.44 drive and 1.22 drive
SELECT product_no, description
FROM product_master
WHERE description IN('1.44 Drive','1.22 Drive');

--12.print info from sales_order in month of Jan
SELECT *
FROM sales_order
WHERE substr(s_order_date,1,2)='01';

--13. find the products whose selling price is greater than 2000 and less than or equal to 5000
SELECT description
FROM product_master
WHERE sell_price BETWEEN 2000 AND 5000

--14. find products whose selling price is more than 1500
SELECT *
FROM product_master
WHERE sell_price > 1500

--15. Find the new SP as original SP*15 & Rename the new column in the above query as new_price
SELECT description, sell_price*15 AS new_price
FROM product_master

--16. Find the products whose CP < 1500
SELECT *
FROM product_master
WHERE cost_price < 1500

--17. List the products in sorted order of their description
SELECT *
FROM product_master
ORDER BY description

--18. Calculate square root of price of each product
SELECT description, sqrt(sell_price) AS root_of_price
FROM product_master

--19. Divide the cost of product '540 HDD' by difference between its price and 100
SELECT cost_price / (sell_price - 100) AS result
FROM product_master
WHERE description = '540 HDD'

--20. List name,city and state of clients not in the state of Maharashtra
SELECT name, city, state
FROM client_master
WHERE state
NOT IN 'Maharashtra' OR state IS NULL

-- 21. List the product_no, description,sell_price of products whose description begin with 'M'
SELECT product_no, description, sell_price
FROM product_master
WHERE description LIKE('M%')

-- 22. List all the orders that were canceled in month of Jan
SELECT *
FROM sales_order
WHERE substr(s_order_date,1,2)='01' AND order_status='Canceled'

-- 23. Count total number of orders
SELECT COUNT(*) AS Orders
FROM sales_order

-- 24. Calc avg price of all products
SELECT AVG(sell_price)
FROM product_master

-- 25. Calc minimum price of products
SELECT MIN(sell_price)
FROM product_master

-- 26. Determine max and min product prices. Rename title as max_price and min_price respectively
SELECT MAX(sell_price) AS Max_Price, MIN(sell_price) AS Min_Price
FROM product_master

-- 27. Count number of products having price >=1500
SELECT COUNT(*)
FROM product_master
WHERE sell_price>=1500

-- 28. Find all products whose qty_on_hand < recorder level
SELECT description
FROM product_master
WHERE qty_on_hand<recorder_lvl

-- 29 a. Print the info of client_master,sales_order table in following format for all records
-- (cust_name) has placed (order_no) on (s_order_date)
SELECT C.name||' has placed order num '||S.s_order_no||' on '||S.s_order_date AS Records
FROM client_master C, sales_order S
WHERE C.client_no = S.client_no

--29  b. Print the info of client_master,sales_order table in following format for all records:
-- (cust_name) has placed (order_no) in the month of (s_order_month)
SELECT C.name||' has placed order num '||S.s_order_no||' in month of '||substr(to_char(S.s_order_date,'DD-MON-YYYY'),4,3) AS Records
FROM client_master C, sales_order S
WHERE C.client_no = S.client_no


--30. Print the description and total qty sold for each product
SELECT P.description , SUM(S.qty_disp)
FROM product_master P, sales_order_details S
WHERE P.product_no=S.product_no
GROUP BY P.description

--31 Find the value of each product sold.
SELECT P.description, SUM(S.qty_disp*p.sell_price) AS value
FROM product_master P, sales_order_details S
WHERE P.product_no=S.product_no
GROUP BY P.description

-- 32. Calculate the average qty sold for each client that has a maximum order value of 15000.00
SELECT AVG(SD.qty_disp), S.client_no
FROM sales_order S, sales_order_details SD
WHERE S.s_order_no=SD.s_order_no AND qty_disp*product_rate<15000
GROUP BY S.client_no

--33. Find out the total sales amount receivable for the month of FEB. It will be the sum total of all the billed orders for the month.
SELECT SUM(SD.qty_disp * SD.product_rate) AS total_sales
FROM sales_order S, sales_order_details SD
WHERE S.s_order_no=SD.s_order_no AND to_char(S.s_order_date,'MON')='FEB' AND billed_yn='Y'

--34. Print the information of product master, order_detail table in the following format 
-- for all the records :- {description} worth Rs. {total sales for the product) was sold.
SELECT P.description||' worth Rs. '||SUM(SD.qty_disp*SD.product_rate)||' was sold.' AS Info
FROM product_master P, sales_order_details SD
WHERE SD.product_no=P.product_no
GROUP BY P.description


-- 35 Print the information of product master, order_detail table in the following format for all records- 
-- {description} worth Rs. {total sales for the product} was ordered in the month of {s_order_date in month format}
SELECT P.description||' worth Rs. '||SUM(SD.qty_ordered*SD.product_rate)||' was ordered in month of '||to_char(S.s_order_date,'MONTH') AS Info
FROM product_master P, sales_order S, sales_order_details SD
WHERE SD.product_no=P.product_no AND S.s_order_no=SD.s_order_no
GROUP BY P.description,to_char(S.s_order_date,'MONTH')
ORDER BY to_char(S.s_order_date,'MONTH')

--1. Change s_order_date of client c0001 to 24/07/1996
UPDATE sales_order SET s_order_date = '07/24/1996' WHERE client_no='C00001'

--2. Change SP of 1.44 Floppies to 1150
UPDATE product_master SET sell_price=1150 WHERE description='1.44 Floppies'

--3. Delete record with order number O19001 from order table
DELETE * FROM sales_order WHERE s_order_no='O19001';

-- 4. delete records having dely_date before 10/07/96
DELETE * FROM sales_order WHERE dely_date='07/10/1996'

--5. Change city of client_no 'C0005' to 'Bombay'
UPDATE client_master SET city='Bombay' WHERE client_no='C00005'

--6. Change dely_date of Order Number 'O10008' to 16-08-96
UPDATE sales_order SET dely_date='08/16/1996' WHERE s_order_no='O10008'

--7. Change bal_due of client_no 'C00001' to 1000
UPDATE client_master SET bal_due = 1000 WHERE client_no='C00001'

-- 8. Change cp of '1.22 Floppies' to 950
UPDATE product_master SET cost_price = 950 WHERE description='1.22 Floppies'
