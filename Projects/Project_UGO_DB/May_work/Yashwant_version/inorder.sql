INSERT INTO ugo_role_type VALUES (11,01,'faculty');
INSERT INTO ugo_role_type VALUES (12,02,'Councellor');
INSERT INTO ugo_role_type VALUES (13,03,'Advisor');

INSERT INTO ugo_course_master VALUES ('CSE330','Formal languages and automata');
INSERT INTO ugo_course_master VALUES ('CSE310','Software Engineering');
INSERT INTO ugo_course_master VALUES ('CSE320','Computer Networks');
INSERT INTO ugo_course_master VALUES ('CSE455','Data Mining');
INSERT INTO ugo_course_master VALUES ('CSE100','Programming Basics');

INSERT INTO ugo_course_offering VALUES ('AM001','CSE330',6,'2017-01-05','2017-05-28','REG','2014');
INSERT INTO ugo_course_offering VALUES ('AM002','CSE310',6,'2017-01-05','2017-05-28','REG','2014');
INSERT INTO ugo_course_offering VALUES ('AM003','CSE320',6,'2017-01-05','2017-05-28','REG','2014');
INSERT INTO ugo_course_offering VALUES ('AM004','CSE455',6,'2017-01-05','2017-05-28','REG','2014');
INSERT INTO ugo_course_offering VALUES ('AM005','CSE100',2,'2017-01-05','2017-05-28','REG','2016');

INSERT INTO ugo_faculty VALUES ('AM.FAC.CSE0001','Dr Sajeev. G.P',123456789,'sajeev@gmail.com','ab',11);
INSERT INTO ugo_faculty VALUES ('AM.FAC.CSE0002','Dr Jyothisha J Nair',9878945661,'jyothisha@gmail.com','ba',13);
INSERT INTO ugo_faculty VALUES ('AM.FAC.CSE0003','Dr Bhadrachalam Chitturi',1234526987,'badRa@gmail.com','cc',11);
INSERT INTO ugo_faculty VALUES ('AM.FAC.CSE0004','Dr Swaminathan J',4567812036,'swamii@gmail.com','cv',12);

INSERT INTO ugo_faculty_role_mapping VALUES (1,'AM.FAC.CSE0001',11);
INSERT INTO ugo_faculty_role_mapping VALUES (2,'AM.FAC.CSE0002',13);
INSERT INTO ugo_faculty_role_mapping VALUES (3,'AM.FAC.CSE0003',11);
INSERT INTO ugo_faculty_role_mapping VALUES (4,'AM.FAC.CSE0004',12);

INSERT INTO ugo_student VALUES ('AM.EN.U4CSE14001','Kri',123,'kri@gmail.com','xx','AM.FAC.CSE0001','AM.FAC.CSE0003',2014,'A');
INSERT INTO ugo_student VALUES ('AM.EN.U4CSE14002','Pri',256,'irp@gmail.com','xy','AM.FAC.CSE0002','AM.FAC.CSE0004',2015,'B');

INSERT INTO ugo_course_student_enrollment VALUES ('AM.EN.U4CSE14001','AM001',1);
INSERT INTO ugo_course_student_enrollment VALUES ('AM.EN.U4CSE14002','AM002',2);

INSERT INTO ugo_course_plan VALUES (1,'AM001',15,15,20,50);
INSERT INTO ugo_course_plan VALUES (2,'AM002',15,15,20,50);

INSERT INTO ugo_attendance VALUES (1,'AM001','2017-01-9',1);
INSERT INTO ugo_attendance VALUES (2,'AM002','2017-01-10',1);

INSERT INTO ugo_absentees VALUES (1,'AM.EN.U4CSE14002',1);


INSERT INTO ugo_leave_type VALUES (1,'Medical');
INSERT INTO ugo_leave_type VALUES (2,'Duty Leave');

INSERT INTO ugo_student_leave VALUES (1,'AM.EN.U4CSE14002',1,'2017-01-09','2017-01-10');

INSERT INTO ugo_activity_type VALUES (1,'abcd');
INSERT INTO ugo_activity_type VALUES (2,'bcd');

INSERT INTO ugo_continuous_eval VALUES (1,'AM001','ABCD',1,15);
INSERT INTO ugo_continuous_eval VALUES (2,'AM002','EFGH',2,15);



INSERT INTO ugo_student_disciplinary VALUES (1,'AM.EN.U4CSE14002',NULL,NULL,NULL,NULL);
INSERT INTO ugo_student_disciplinary VALUES (2,'AM.EN.U4CSE14001',NULL,NULL,NULL,NULL);

INSERT INTO ugo_student_achievement VALUES (1,'AM.EN.U4CSE14002','Dance','2017-01-21',5,NULL);
INSERT INTO ugo_student_achievement VALUES (2,'AM.EN.U4CSE14001','ICPC','2017-02-15',2,NULL);


INSERT INTO ugo_student_continuous_eval VALUES (1,'AM.EN.U4CSE14002',1,9.9);
INSERT INTO ugo_student_continuous_eval VALUES (2,'AM.EN.U4CSE14001',2,19.9);

INSERT INTO ugo_student_mark VALUES (1,'AM.EN.U4CSE14001','AM001',10,13.6,19.9,35.19,'B+');
INSERT INTO ugo_student_mark VALUES (2,'AM.EN.U4CSE14002','AM002',0,3.6,9.9,15.19,'D');
