CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      WITH my_cte AS(
          select *,DENSE_RANK() over(ORDER BY salary DESC) as rnk from Employee
      )
      SELECT DISTINCT CASE
          WHEN salary IS NOT NULL THEN salary
          ELSE NULL
      END
      from my_cte where rnk=n
  );
END