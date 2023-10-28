with mycte as (
    select *,dense_rank() over(partition by departmentId order by salary desc) as 'rank' from Employee 
)
select d.name as "Department",mycte.name as 'Employee',mycte.salary as 'Salary' from mycte,department d where mycte.departmentid=d.id and mycte.rank<=3;