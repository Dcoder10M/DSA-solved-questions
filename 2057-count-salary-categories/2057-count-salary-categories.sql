select "Low Salary" as category,
count(*) as accounts_count
from Accounts where income<20000
union
select "Average Salary" category,
sum(case when income >= 20000 and income <= 50000 then 1 else 0 end) as accounts_count
from Accounts
union
select "High Salary" category,
sum(case when income>50000 then 1 else 0 end) as accounts_count
from Accounts