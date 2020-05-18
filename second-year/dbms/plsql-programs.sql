--Reverse a string(varchar2() .. take input from user)

SET SERVEROUTPUT ON
ACCEPT  word PROMPT 'Enter string to reverse: ';
DECLARE 
 str varchar2(30);
revStr varchar2(30):='';
BEGIN
    str:='&word';
    FOR i IN REVERSE 1..length(str) LOOP
        revStr:=revStr||substr(str,i,1);
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('The reverse of '||str||' is '||revStr);
END;
/

-- Fibonacci Series for n terms
SET SERVEROUTPUT ON

ACCEPT terms PROMPT 'Enter number of terms: ';
DECLARE
n number(3); 
x number(3) := 0 ; 
y number(3) := 1 ; 
z number(3); 
i number(3):=3;
BEGIN
n:=&terms;
DBMS_OUTPUT.PUT_LINE
('The series is: ');
IF n>0 THEN 
DBMS_OUTPUT.PUT_LINE('0');
END IF; 
IF n>1 THEN 
DBMS_OUTPUT.PUT_LINE('1');
END IF; 
WHILE i<=n LOOP 
z:=x+y; 
DBMS_OUTPUT.PUT_LINE(z);
x:=y;
y:=z;
i:=i+1;
END LOOP;
END; 
/
-- Print first n prime numbers
SET SERVEROUTPUT ON
ACCEPT var PROMPT 'Enter no. of prime num to display ';
DECLARE
    n number(3):=0;
    flag number(1):=0;
    limit number(3);
BEGIN
    limit:=&var;
FOR i IN 2..1000 LOOP
    FOR j IN 2..i-1 LOOP
        IF MOD(i,j)=0 THEN
            flag:=1;
            EXIT;
        END IF;
    END LOOP;
    IF flag = 0 THEN
        DBMS_OUTPUT.PUT_LINE(i);
        n:=n+1;
    END IF;
    IF n=limit THEN
        EXIT;
    END IF;
    flag:=0;
END LOOP;

END;
/
-- Cursor
-- Employee
-- (emp_code,emp_name,salary,dept_no)
-- Find all employees in dept num 2 and raise their salary 5% and
-- insert the data into another table salary_hike which also contains date of salary hike

CREATE TABLE employee12
(
    emp_code varchar2(10) PRIMARY KEY,
    emp_name char(30) NOT NULL,
    salary number(6),
    dept_no number(2)
);

INSERT INTO employee12
VALUES('E01', 'Aadhar', 25000, 1);
INSERT INTO employee12
VALUES('E02', 'Abhijeet', 35000, 2);
INSERT INTO employee12
VALUES('E03', 'Ankush', 40000, 1);
INSERT INTO employee12
VALUES('E04', 'Aditya', 36500, 1);
INSERT INTO employee12
VALUES('E05', 'Kashish', 40000, 2);
INSERT INTO employee12
VALUES('E06', 'Eva', 45000, 2);
INSERT INTO employee12
VALUES('E07', 'Ishita', 75000, 2);
INSERT INTO employee12
VALUES('E08', 'Aman', 55000, 2);

CREATE TABLE salary_hike12 AS
SELECT *
FROM employee12
WHERE 0=1;

ALTER TABLE salary_hike12
DROP COLUMN emp_name;
ALTER TABLE salary_hike12
DROP COLUMN dept_no;
ALTER TABLE salary_hike12
DROP COLUMN emp_name;
ALTER TABLE salary_hike12
 RENAME TO salary_hike_dept02

SET SERVEROUTPUT ON
DECLARE 
    counter number(3):=0;
    CURSOR c_emp12 IS
    SELECT emp_code, salary
    FROM employee12
    WHERE dept_no=2;
    var_emp_code employee12.emp_code%type;
    var_salary employee12.salary%type;
BEGIN
    OPEN c_emp12;
    LOOP
        FETCH c_emp12
        INTO var_emp_code,var_salary;
        IF c_emp12%NOTFOUND THEN
            EXIT;
        END IF;
        UPDATE employee12 SET salary=salary+(var_salary*0.05) WHERE emp_code=var_emp_code;
        INSERT INTO salary_hike_dept02
        VALUES(var_emp_code, var_salary, SYSDATE);
        counter:=counter+1;
        DBMS_OUTPUT.PUT_LINE(counter||'record(s) updated');
    END LOOP;
    CLOSE c_emp12;
END;
/

SET SERVEROUTPUT ON;
DECLARE
    CURSOR c_emp121 IS
    SELECT *
    FROM employee12
    ORDER BY salary DESC;
    var_emp c_emp121%rowtype;
BEGIN
    OPEN c_emp121;
    LOOP
        FETCH c_emp121
        INTO var_emp;
        IF c_emp121%rowcount=6 THEN 
        EXIT;
        END IF;
        DBMS_OUTPUT.PUT_LINE('Name '||var_emp.emp_name||' Salary '||var_emp.salary);
    END LOOP;
END;
/