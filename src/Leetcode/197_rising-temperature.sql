Select x.id
from Weather w
    inner join Weather x
    on ADDDATE(w.recordDate,1)=x.recordDate
where x.temperature > w.temperature;