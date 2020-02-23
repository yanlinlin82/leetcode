# https://leetcode-cn.com/problems/nth-highest-salary/
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
    # Write your MySQL query statement below.
    SELECT NthHighestSalary INTO @a
    FROM (SELECT N AS id) AS a
    LEFT JOIN (
      SELECT
      @i := @i + 1 AS id,
      t.*
      FROM
      (SELECT DISTINCT(Salary) AS NthHighestSalary FROM Employee ORDER BY Salary DESC) AS t,
      (SELECT @i := 0) AS foo
    ) AS b ON a.id = b.id
    LIMIT 1;
    @a
  );
END
