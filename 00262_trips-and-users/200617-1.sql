-- https://leetcode-cn.com/problems/trips-and-users/
SELECT
  Request_at Day,
  ROUND(SUM(Status != 'completed') / COUNT(*), 2) AS `Cancellation Rate`
FROM (
  SELECT * FROM Trips
  WHERE Client_Id IN (SELECT Users_Id FROM Users WHERE Banned = 'No' AND Role = 'client')
  AND Driver_Id IN (SELECT Users_Id FROM Users WHERE Banned = 'No' AND Role = 'driver')
  AND Request_at BETWEEN '2013-10-01' AND '2013-10-03'
) a
GROUP BY Request_at;
