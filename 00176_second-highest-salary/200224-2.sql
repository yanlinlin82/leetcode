# https://leetcode-cn.com/problems/second-highest-salary/
# SELECT ... INTO 语句无法在leetcode平台上编译通过，但本地可以正确运行

# SQL schema
Create table If Not Exists Employee (Id int, Salary int);
Truncate table Employee;
insert into Employee (Id, Salary) values ('1', '100');
insert into Employee (Id, Salary) values ('2', '200');
insert into Employee (Id, Salary) values ('3', '300');

# Write your MySQL query statement below
SET @a = NULL;
SELECT DISTINCT(Salary) INTO @a
  FROM Employee
  ORDER BY Salary DESC
  LIMIT 1,1;
SELECT @a AS SecondHighestSalary;
