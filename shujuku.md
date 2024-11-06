* 5_7
* create view test5_07 as select sid,name,dname,ds_score,os_score
  from
(select distinct sid,name,dname from pub.student natural join pub.student_course where cid in (select cid from pub.course where cid =300002 or cid =300005) and dname='计算机科学与技术学院'）
  natural left outer join
(select distinct sid,max(score) as ds_score 
from pub.student natural join pub.student_course
where cid =300002
group by sid,dname )
  natural left outer join
(select distinct sid,max(score) as os_score 
from pub.student natural join pub.student_course
where cid = 300005 
group by sid ,dname)

* 6——3
* select cid ,name ,ms,sum(score) as max_score_count
  from(
select cid ,name ,ms
  from pub.course natural left join (select cid,max(score) as ms from pub.student_course group by cid)
)

