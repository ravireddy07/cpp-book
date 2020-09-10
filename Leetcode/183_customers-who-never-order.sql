<!-- https://leetcode.com/problems/customers-who-never-order/ 

<!-- https://leetcode.com/problems/customers-who-never-order/discuss/839191/MySQL-Simple-Solution-or-Beats-100-in-Less-Space-or-Self-Explanatory

select
    c.Name as 'Customers'
from Customers c
where not exists (select o.CustomerId
from Orders o
where c.Id = o.CustomerId);