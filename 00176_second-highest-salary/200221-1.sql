# Write your MySQL query statement below
select SecondHighestSalary
from (select 2 as id) as a
left join (
    select
        @i := @i + 1 as id,
        t.*
    from
        (select distinct(Salary) as SecondHighestSalary from Employee order by Salary desc limit 2) as t,
        (select @i := 0) as foo
) as b on a.id = b.id;
