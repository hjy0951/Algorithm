-- 코드를 입력하세요
SELECT SUBSTRING(DATETIME, 12, 2) AS HOUR, COUNT(*) AS COUNT
FROM ANIMAL_OUTS
GROUP BY HOUR
HAVING HOUR BETWEEN 9 AND 19;