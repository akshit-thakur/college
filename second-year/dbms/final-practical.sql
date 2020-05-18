-- Table:
-- (R no,Fn,Ln,Major,GPA)
-- Varchar PK
-- Fn,ln,major char 
-- Gpa 3,1

-- Find max gpa through pl sql

-- How many students have max gpa

-- If count>1
-- There are x number of student
-- with gpa ..
-- Else 
-- Ln,Major

CREATE TABLE student
(
    roll_num varchar2(8) PRIMARY KEY,
    first_name char(20) NOT NULL,
    last_name char(20),
    major char(10) NOT NULL,
    gpa number(3,1) NOT NULL
);
INSERT INTO student
VALUES('1', 'Aadhar', 'Sharma', 'CSE', 98);
INSERT INTO student
VALUES('2', 'Pooja', 'Chaudhary', 'IT', 88);
INSERT INTO student
VALUES('3', 'Aakansha', '', 'EEE', 89);
INSERT INTO student
VALUES('4', 'Akhilesh', 'Yadav', 'EEE', 95);
INSERT INTO student
VALUES('5', 'Aditi', 'Sharma', 'Biotech', 98);


--PL/SQL
SET SERVEROUTPUT ON;

DECLARE
 
v_last_name student.last_name%type;
v_major student.major%type;
v_max_gpa number
(3,1);
v_numstudents number
(4);

BEGIN
    SELECT MAX(gpa)
    INTO v_max_gpa
    FROM student;
    DBMS_OUTPUT.PUT_LINE
    ('The higest GPA is '||v_max_gpa);
    SELECT COUNT(roll_num)
    INTO v_numstudents
    FROM student
    WHERE gpa=v_max_gpa;

    IF v_numstudents > 1 then
DBMS_OUTPUT.PUT_LINE
    ('There are '||v_numstudents||' with higest GPA');
ELSE
SELECT last_name, major
INTO v_last_name
,v_major FROM student WHERE gpa=v_max_gpa; 
DBMS_OUTPUT.PUT_LINE
('Last Name : '||v_last_name);
DBMS_OUTPUT.PUT_LINE
('Major : '||v_major);
END
IF;
 
END;
/
