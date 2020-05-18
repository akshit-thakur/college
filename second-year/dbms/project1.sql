DESC employee;
DESC department;
DESC dept_location;
DESC project;
DESC dependent;
DESC workson;

SELECT * FROM employee;
SELECT * FROM department;
SELECT * FROM dept_location;
SELECT * FROM project;
SELECT * FROM dependent;
SELECT * FROM workson;

CREATE TABLE employee
(
    ssn varchar2(6),
    bdate date NOT NULL,
    address varchar2(30) NOT NULL,
    first_name char(15) NOT NULL,
    middle_name char(10),
    last_name char(15),
    sex char(1) default 'M',
    salary int,
    essn varchar2(6),
    CONSTRAINT PK_EMP PRIMARY KEY(ssn),
    CONSTRAINT FK_EMP FOREIGN KEY(essn) REFERENCES Employee(ssn)
);

CREATE TABLE department
(
    dept_name char(10) NOT NULL,
    dept_num int,
    dept_location char(20) NOT NULL,
    dssn varchar2(6),
    CONSTRAINT PK_DEPT PRIMARY KEY(dept_num)
);


ALTER TABLE Department
DROP COLUMN dept_location

ALTER TABLE Department
ADD start_date date

ALTER TABLE Department
ADD CONSTRAINT FK_DEPT FOREIGN KEY(dssn) REFERENCES Employee(ssn) ON DELETE SET NULL

ALTER TABLE Employee
ADD did int;

ALTER TABLE Employee
ADD CONSTRAINT FK_EMP_DEPT FOREIGN KEY(did) REFERENCES Department(dept_num) ON DELETE SET NULL


CREATE TABLE dept_location
(
    dept_num int,
    dept_location char(50),
    CONSTRAINT PK_LOC PRIMARY KEY(dept_num,dept_location),
    CONSTRAINT FK_DEPT_LOC FOREIGN KEY(dept_num) REFERENCES department(dept_num)
);

CREATE TABLE project
(
    proj_num int,
    proj_name char(15),
    proj_location char(50),
    proj_did int,
    CONSTRAINT FK_PROJ_DEPT FOREIGN KEY(proj_did) REFERENCES Department(dept_num),
    CONSTRAINT PK_PROJ PRIMARY KEY(proj_num)
);

CREATE TABLE dependent
(
    ssn varchar2(6) NOT NULL,
    name char(10) NOT NULL,
    sex char(1) default 'M',
    birth_date date NOT NULL,
    relationship char(20) NOT NULL,
    CONSTRAINT FK_DEPD FOREIGN KEY(ssn) REFERENCES Employee(ssn),
    CONSTRAINT PK_DEPD PRIMARY KEY(name,ssn)
);

CREATE TABLE workson
(
    ssn varchar2(6),
    proj_num int,
    hours int NOT NULL,
    CONSTRAINT PK_WORKS PRIMARY KEY(ssn,proj_num),
    CONSTRAINT FK_WORKS_EMP FOREIGN KEY(ssn) REFERENCES Employee(ssn) ON DELETE CASCADE,
    CONSTRAINT FK_WORKS_PROJ FOREIGN KEY(proj_num) REFERENCES Project(proj_num) ON DELETE CASCADE
);


ALTER TABLE Employee
ADD CONSTRAINT CHECK_SSN CHECK(ssn like 'E%')

ALTER TABLE Dependent
ADD CONSTRAINT DEPD_RELATION_VAL CHECK(relationship IN('Father','Mother','Sister','Wife','Son','Daughter'))

ALTER TABLE Project
ADD CONSTRAINT FK_PROJ_DEPT FOREIGN KEY(proj_did) REFERENCES Department(dept_num) on delete cascade

ALTER TABLE Employee
ADD CONSTRAINT d1 CHECK(to_char(bdate,'mm/dd/yyyy')<'08/14/2018');

ALTER TABLE Dependent
DROP CONSTRAINT FK_DEPD

ALTER TABLE Dependent
ADD CONSTRAINT FK_DEPD FOREIGN KEY(ssn) REFERENCES Employee(ssn) ON DELETE CASCADE


INSERT INTO Employee
VALUES('E01', '01/25/1995', 'Sector 23,Chandigarh', 'Aditi', '', 'Sharma', 'F', '40000', '', '')

INSERT INTO Employee
VALUES('E02', '05/05/1997', 'Sector 44,Chandigarh', 'Aman', '', 'Kapoor', 'M', '30000', 'E01', '')

INSERT INTO Employee
VALUES('E03', '01/02/1990', 'Sector 35,Chandigarh', 'Amit', '', 'Sahni', 'M', '50000', '', '')

INSERT INTO Employee
VALUES('E04', '03/19/1996', 'Sector 43,Chandigarh', 'Anita', '', '', 'F', '45000', 'E03', '')

INSERT INTO Department
VALUES('Marketing', '1', 'E01', '01/01/2010')

INSERT INTO Department
VALUES('Designing', '2', 'E03', '07/01/2013')

INSERT INTO Project
VALUES('1', 'ABC', 'Sector 21', '1')

INSERT INTO Project
VALUES('2', 'XYZ', 'Sector 33', '2')

INSERT INTO Project
VALUES('9', 'DEF', 'Sector 35', '2')

INSERT INTO Dependent
VALUES
    ('E01', 'Vikrant', 'M', '08/08/1970', 'Father')

INSERT INTO Dependent
VALUES
    ('E02', 'Yukta', 'F', '12/12/1975', 'Mother')

INSERT INTO Dependent
VALUES
    ('E03', 'Payal', 'F', '12/29/1993', 'Wife')

INSERT INTO Dependent
VALUES
    ('E04', 'Vikram', 'M', '11/11/1972', 'Father')

INSERT INTO Dependent
VALUES
    ('E04', 'Vaishali', 'F', '11/11/1977', 'Mother')

INSERT INTO dept_location
VALUES
    ('1', 'Sector 35 Chandigarh')

INSERT INTO dept_location
VALUES
    ('1', 'Sector 4, Panchkula')

INSERT INTO dept_location
VALUES
    ('1', 'Phase X, Mohali')

INSERT INTO dept_location
VALUES
    ('2', 'Sector 22, Chandigarh')

INSERT INTO dept_location
VALUES
    ('2', 'Sector 10, Panchkula')

INSERT INTO dept_location
VALUES
    ('2', 'Phase VII, Mohali')

INSERT INTO workson
VALUES('E02', '1', '5')

INSERT INTO workson
VALUES('E01', '1', '5')

INSERT INTO workson
VALUES('E03', '2', '8')

INSERT INTO workson
VALUES('E04', '2', '8')

INSERT INTO workson
VALUES('E03', '9', '6')


UPDATE employee SET did='1' WHERE ssn='E01'

UPDATE employee SET did='1' WHERE ssn='E02'

UPDATE employee SET did='2' WHERE ssn='E03'

UPDATE employee SET did='2' WHERE ssn='E04'

SELECT *
FROM employee
WHERE did=1

SELECT *
FROM workson
WHERE proj_num=9

SELECT ssn
FROM workson
WHERE proj_num=9

INSERT INTO employee
VALUES('E05', '07/05/1993', 'Sector 15,Chandigarh', 'Chirag', '', 'Arora', 'M', '70000', 'E02', '1')

INSERT INTO employee
VALUES('E06', '07/09/1996', 'Sector 25,Chandigarh', 'Dhruv', '', '', 'M', '80000', 'E01', '1')

INSERT INTO employee
VALUES('E07', '01/03/1994', 'Sector 47,Chandigarh', 'Harmanpreet', '', 'Kaur', 'F', '60000', 'E04', '2')

INSERT INTO employee
VALUES('E08', '03/27/1995', 'Sector 36,Chandigarh', 'Ishita', '', 'Sharma', 'F', '55000', 'E07', '2')

INSERT INTO dependent
VALUES('E07', 'Amit', 'M', '12/12/1966', 'Father')

INSERT INTO dependent
VALUES('E07', 'Vikramjeet', 'M', '03/01/1993', 'Husband')

INSERT INTO dependent
VALUES('E08', 'Roshni', 'F', '12/21/1969', 'Mother')

INSERT INTO dependent
VALUES('E08', 'Avantika', 'F', '07/11/1998', 'Sister')

INSERT INTO dependent
VALUES('E05', 'Diya', 'F', '05/07/1994', 'Wife')

INSERT INTO dependent
VALUES('E06', 'Smriti', 'F', '09/07/1971', 'Mother')

INSERT INTO dependent
VALUES('E06', 'Vanshika', 'F', '11/11/1991', 'Sister')

INSERT INTO  workson
VALUES('E05', '1', '7')

INSERT INTO  workson
VALUES('E06', '1', '8')

INSERT INTO  workson
VALUES('E07', '2', '4')

INSERT INTO  workson
VALUES('E07', '9', '7')

INSERT INTO  workson
VALUES('E08', '2', '8')

INSERT INTO  workson
VALUES('E08', '9', '7')

--queries
SELECT *
FROM dept_location
WHERE dept_num=2

SELECT *
FROM employee
WHERE salary>40000

SELECT avg(salary)
FROM employee
WHERE did=1

SELECT count(ssn)
FROM employee
WHERE sex='F'

SELECT ssn, count(name)
FROM dependent
GROUP BY ssn

SELECT ssn, sum(hours)
FROM workson
GROUP BY ssn
SELECT first_name, last_name
FROM employee
ORDER BY bdate
SELECT P.proj_name

, P.proj_location, count(W.ssn)
FROM project P, workson W
WHERE P.proj_num=W.proj_num
GROUP BY P.proj_name,P.proj_location

SELECT ssn, first_name
FROM employee
WHERE last_name='Sharma'

SELECT D.dept_num
FROM department D, dept_location DL
WHERE D.dept_num=DL.dept_num
GROUP BY D.dept_num
HAVING count(*)>2
