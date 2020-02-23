# https://leetcode-cn.com/problems/nth-highest-salary/

# SQL schema
Create table If Not Exists Employee (Id int, Salary int);
Truncate table Employee;
insert into Employee (Id, Salary) values ('1', '100');
insert into Employee (Id, Salary) values ('2', '200');
insert into Employee (Id, Salary) values ('3', '300');

# Answer
DROP FUNCTION IF EXISTS getNthHighestSalary;
DELIMITER //
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
DETERMINISTIC
BEGIN
    # Write your MySQL query statement below.
    DECLARE a INT;
    SELECT Salary INTO a
    FROM (SELECT N AS id) AS a
    LEFT JOIN (
      SELECT
        @i := @i + 1 AS id,
        t.*
      FROM
        (SELECT DISTINCT(Salary) AS Salary FROM Employee ORDER BY Salary DESC) AS t,
        (SELECT @i := 0) AS foo
    ) AS b ON a.id = b.id;
    RETURN a;
END//
DELIMITER ;
