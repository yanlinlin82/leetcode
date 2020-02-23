# https://leetcode-cn.com/problems/consecutive-numbers/
# 挑战失败：本地测试成功代码，leetcode不支持

# SQL schema

Create table If Not Exists Logs (Id int, Num int);
Truncate table Logs;
insert into Logs (Id, Num) values ('1', '1');
insert into Logs (Id, Num) values ('2', '1');
insert into Logs (Id, Num) values ('3', '1');
insert into Logs (Id, Num) values ('4', '2');
insert into Logs (Id, Num) values ('5', '1');
insert into Logs (Id, Num) values ('6', '2');
insert into Logs (Id, Num) values ('7', '2');

# Write your MySQL query statement below
DROP PROCEDURE IF EXISTS FetchConsecutiveNums;
DROP TABLE IF EXISTS ConsecutiveNums;
CREATE TABLE ConsecutiveNums (ConsecutiveNums INT, PRIMARY KEY(ConsecutiveNums));
DELIMITER //
CREATE PROCEDURE FetchConsecutiveNums()
BEGIN
  DECLARE done INT DEFAULT FALSE;
  DECLARE last INT;
  DECLARE cnt INT;
  DECLARE x INT;
  DECLARE cur CURSOR FOR SELECT Num FROM Logs ORDER BY Id;
  DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;
  SET last = 0;
  SET cnt = -1;
  SET x = 0;
  DELETE FROM ConsecutiveNums;
  OPEN cur;
  r: LOOP
    FETCH cur INTO x;
    IF done = 1 THEN LEAVE r; END IF;
    IF (cnt = -1 OR last <> x) THEN
      SET last = x;
      SET cnt = 1;
    ELSE
      SET cnt = cnt + 1;
      IF (cnt >= 3) THEN
        INSERT INTO ConsecutiveNums VALUES (x);
      END IF;
    END IF;
  END LOOP r;
  CLOSE cur;
  SELECT * FROM ConsecutiveNums;
END//
DELIMITER ;
CALL FetchConsecutiveNums();
