SELECT * FROM date_table WHERE u_date>'2020-1-20';
- 1 | 2020-01-21
- 2 | 2020-10-21
- 9 | 2038-01-19
+ 1 | 202001202001
+ 2 | 202010202010
+ 9 | 203801203801
-- below are some requests executed before(partial) --
-- init data
CREATE TABLE date_table(id int, u_date date);
CREATE INDEX index_id on date_table(u_date);
INSERT INTO date_table VALUES (1,'2020-01-21');
INSERT INTO date_table VALUES (2,'2020-10-21');
INSERT INTO date_table VALUES (3,'2020-1-01');
...