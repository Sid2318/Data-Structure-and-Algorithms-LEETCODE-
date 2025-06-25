SELECT r.contest_id , ROUND(COUNT(DISTINCT r.user_id)*100 / (SELECT COUNT(*) FROM Users),2) AS percentage
FROM Register r
GROUP BY r.contest_id
ORDER BY percentage DESC, contest_id ASC;

# Write your MySQL query statement below
-- select r.contest_id as contest_id , Round(count(r.contest_id)/(select count(u.user_id)),2) as percentage
-- from Register r
-- left join Users u
-- on r.user_id = u.user_id
-- Group by r.contest_id;
