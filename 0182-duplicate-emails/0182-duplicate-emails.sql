# Write your MySQL query statement below
with cte as(select *,count(*) over(partition by email) as "cnt" from Person)
select Distinct Email from cte where cnt>1