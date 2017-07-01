CREATE TABLE ugo_faculty (
    fid varchar(20),
    faculty_name varchar(50),
    faculty_contact_no varchar(20),
    faculty_email varchar(20),
    faculty_device_id varchar(20),
    roleid int(11),
    PRIMARY KEY (fid)
);

CREATE TABLE ugo_student (
    sid varchar(20),
    student_name varchar(50),
    student_contact_no integer,
    student_email varchar(20),
    student_device_id varchar(20),
    counselorid varchar(20),
    advisorid varchar(20),
    batch int(4),
    section varchar(4),
    PRIMARY KEY (sid),
    FOREIGN KEY (counselorid) REFERENCES ugo_faculty(fid),
    FOREIGN KEY (advisorid) REFERENCES ugo_faculty(fid)
);

CREATE TABLE ugo_role_type (
    roleid integer,
    role_type integer,
    role_desc varchar(20),
    PRIMARY KEY (roleid)
);

CREATE TABLE ugo_faculty_role_mapping (
    ufrid integer,
    fid varchar(20),
    roleid integer,
    PRIMARY KEY (ufrid),
    FOREIGN KEY (roleid) REFERENCES ugo_role_type(roleid),
    FOREIGN KEY (fid) REFERENCES ugo_faculty(fid)
);


CREATE TABLE ugo_course_master (
    cid varchar(20),
    course_name varchar(50),
    PRIMARY KEY (cid)
);


CREATE TABLE ugo_course_offering (
    coid varchar(20),
    cid varchar(20),
    semester integer,
    sem_start date,
    sem_end date,
    sem_type varchar(20),
    PRIMARY KEY (coid),
    FOREIGN KEY (cid) REFERENCES ugo_course_master(cid)
);

CREATE TABLE ugo_course_faculty_allocation (
    fid varchar(20),
    cOid varchar(20),
    cfaid integer,
    PRIMARY KEY (cfaid),
    FOREIGN KEY (fid) REFERENCES ugo_faculty(fid),
    FOREIGN KEY (coid) REFERENCES ugo_course_offering(coid)
);

CREATE TABLE ugo_course_student_enrollment (
    sid varchar(20),
    coid varchar(20),
    cseid integer,
    PRIMARY KEY (cseid),
    FOREIGN KEY (sid) REFERENCES ugo_student(sid),
    FOREIGN KEY (coid) REFERENCES ugo_course_offering(coid)
);


CREATE TABLE ugo_attendance (
    aid integer,
    coid varchar(20),
    a_date date,
    period integer,
    PRIMARY KEY (aid),
    FOREIGN KEY (coid) REFERENCES ugo_course_offering(coid)
);


CREATE TABLE ugo_absentees (
    attendance_abid integer,
    sid varchar(20),
    abid integer,
    PRIMARY KEY (abid),
    FOREIGN KEY (sid) REFERENCES ugo_student(sid)
);


/*COMMENT ON TABLE ugo_absentees
    IS 'In this table, only aid and sid are stored. Leave is sanctioned by Councilor and only the corresponding record in this table has to be deleted.';
*/

CREATE TABLE ugo_leave_type (
    ltd integer,
    leave_description varchar(20),
    PRIMARY KEY (ltd)
);

CREATE TABLE ugo_student_leave (
    lid integer,
    sid varchar(20),
    ltd integer,
    leave_from date,
    leave_to date,
    PRIMARY KEY (lid),
    FOREIGN KEY (sid) REFERENCES ugo_student(sid),
    FOREIGN KEY (ltd) REFERENCES ugo_leave_type(ltd)
);



CREATE TABLE ugo_course_plan (
    cpid integer,
    coid varchar(20),
    fp_weightage integer,
    sp_weightage integer,
    continuous_weightage integer,
    end_sem_weightage integer,
    PRIMARY KEY (cpid),
    FOREIGN KEY (coid) REFERENCES ugo_course_offering(coid)
);


/*COMMENT ON COLUMN ugo_course_plan.continuous_weightage
    IS 'Continuous evaluation can be customised by the faculty like on-line test, no of assignments, presentations, other activities. We capature the total percentage only here. There will  be another table for continous evaluation.';
*/
CREATE TABLE ugo_student_mark (
    smid integer,
    sid varchar(20),
    coid varchar(20),
    fp_mark real,
    sp_mark real,
    continuous_mark real,
    end_sem_mark real,
    grade varchar(2),
    PRIMARY KEY (smid),
    FOREIGN KEY (sid) REFERENCES ugo_student(sid),
    FOREIGN KEY (coid) REFERENCES ugo_course_offering(coid)
);

CREATE TABLE ugo_activity_type (
    actid integer,
    activity_name varchar(50),
    PRIMARY KEY (actid)
);

CREATE TABLE ugo_continuous_eval (
    ceid integer,
    coid varchar(20),
    actid integer,
    activity_desc varchar(20),
    max_mark real,
    PRIMARY KEY (ceid),
    FOREIGN KEY (coid) REFERENCES ugo_course_offering(coid),
    FOREIGN KEY (actid) REFERENCES ugo_activity_type(actid)
);


CREATE TABLE ugo_student_continuous_eval (
    sceid integer,
    sid varchar(20),
    ceid integer,
    mark real,
    PRIMARY KEY (sceid),
    FOREIGN KEY (sid) REFERENCES ugo_student(sid),
    FOREIGN KEY (ceid) REFERENCES ugo_continuous_eval(ceid)
);


CREATE TABLE ugo_student_achievement (
    said integer,
    sid varchar(20),
    event varchar(20),
    e_date_begin date,
    e_date_end date,
    remarks varchar(20),
    PRIMARY KEY (said),
    FOREIGN KEY (sid) REFERENCES ugo_student(sid)
);

/*COMMENT ON COLUMN ugo_student_achievement.remarks
    IS 'Brief description about prize, participation, prize money etc.';
*/

CREATE TABLE ugo_notifications (
    nid integer,
    message varchar(20),
    PRIMARY KEY (nid)
);


CREATE TABLE ugo_notification_student (
    sid varchar(20),
    nid integer,
    FOREIGN KEY (sid) REFERENCES ugo_student(sid),
    FOREIGN KEY (nid) REFERENCES ugo_notifications(nid)
);


CREATE TABLE ugo_notification_faculty (
    fid varchar(20),
    nid integer,
    FOREIGN KEY (fid) REFERENCES ugo_faculty(fid),
    FOREIGN KEY (nid) REFERENCES ugo_notifications(nid)
);

CREATE TABLE ugo_chat_faculty_faculty (
    chatid_ff varchar(20),
    faculty1_id varchar(20),
    faculty2_id varchar(20),
    faculty1_send boolean,
    message varchar(20),
    PRIMARY KEY (chatid_ff),
    FOREIGN KEY (faculty1_id) REFERENCES ugo_faculty(fid),
    FOREIGN KEY (faculty2_id) REFERENCES ugo_faculty(fid)
);

CREATE TABLE ugo_chat_faculty_student (
    chatid_fs varchar(20),
    faculty_id varchar(20),
    student_id varchar(20),
    faculty_send boolean,
    message varchar(20),
    PRIMARY KEY (chatid_fs),
    FOREIGN KEY (faculty_id) REFERENCES ugo_faculty(fid),
    FOREIGN KEY (student_id) REFERENCES ugo_student(sid)
);


CREATE TABLE ugo_student_disciplinary (
    sdid integer,
    sid varchar(20),
    event varchar(20),
    st_date date,
    en_date date,
    remarks varchar(20),
    PRIMARY KEY (sdid),
    FOREIGN KEY (sid) REFERENCES ugo_student(sid)
);

CREATE TABLE ugo_timetable (
    ttid integer,
    coid varchar(20),
    day varchar(20),
    period integer,
    PRIMARY KEY (ttid),
    FOREIGN KEY (coid) REFERENCES ugo_course_offering(coid)
);