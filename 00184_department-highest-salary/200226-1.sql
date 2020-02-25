# https://leetcode-cn.com/problems/department-highest-salary/

# SQL schema

Create table If Not Exists Employee (Id int, Name varchar(255), Salary int, DepartmentId int);
Create table If Not Exists Department (Id int, Name varchar(255));
Truncate table Employee;
insert into Employee (Id, Name, Salary, DepartmentId) values ('1', 'Joe', '70000', '1');
insert into Employee (Id, Name, Salary, DepartmentId) values ('2', 'Jim', '90000', '1');
insert into Employee (Id, Name, Salary, DepartmentId) values ('3', 'Henry', '80000', '2');
insert into Employee (Id, Name, Salary, DepartmentId) values ('4', 'Sam', '60000', '2');
insert into Employee (Id, Name, Salary, DepartmentId) values ('5', 'Max', '90000', '1');
Truncate table Department;
insert into Department (Id, Name) values ('1', 'IT');
insert into Department (Id, Name) values ('2', 'Sales');

# Write your MySQL query statement below

SELECT Department.Name AS Department, Employee.Name AS Employee, Employee.Salary
  FROM Department
  INNER JOIN (
    SELECT DepartmentId, MAX(Salary) AS Salary
      FROM Employee
      GROUP BY DepartmentId
  ) AS t
  ON Department.Id = t.DepartmentId
  INNER JOIN Employee
  ON t.DepartmentId = Employee.DepartmentId AND t.Salary = Employee.Salary;
