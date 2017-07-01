-- MySQL dump 10.13  Distrib 5.7.17, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: ugo_master
-- ------------------------------------------------------
-- Server version	5.7.17-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `ugo_absentees`
--

DROP TABLE IF EXISTS `ugo_absentees`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_absentees` (
  `attendance_abid` int(11) DEFAULT NULL,
  `sid` varchar(20) DEFAULT NULL,
  `abid` int(11) NOT NULL,
  PRIMARY KEY (`abid`),
  KEY `sid` (`sid`),
  CONSTRAINT `ugo_absentees_ibfk_1` FOREIGN KEY (`sid`) REFERENCES `ugo_student` (`sid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_absentees`
--

LOCK TABLES `ugo_absentees` WRITE;
/*!40000 ALTER TABLE `ugo_absentees` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_absentees` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ugo_activity_type`
--

DROP TABLE IF EXISTS `ugo_activity_type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_activity_type` (
  `actid` int(11) NOT NULL,
  `activity_name` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`actid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_activity_type`
--

LOCK TABLES `ugo_activity_type` WRITE;
/*!40000 ALTER TABLE `ugo_activity_type` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_activity_type` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ugo_attendance`
--

DROP TABLE IF EXISTS `ugo_attendance`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_attendance` (
  `aid` int(11) NOT NULL,
  `coid` varchar(20) DEFAULT NULL,
  `a_date` date DEFAULT NULL,
  `period` int(11) DEFAULT NULL,
  PRIMARY KEY (`aid`),
  KEY `coid` (`coid`),
  CONSTRAINT `ugo_attendance_ibfk_1` FOREIGN KEY (`coid`) REFERENCES `ugo_course_offering` (`coid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_attendance`
--

LOCK TABLES `ugo_attendance` WRITE;
/*!40000 ALTER TABLE `ugo_attendance` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_attendance` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ugo_chat_faculty_faculty`
--

DROP TABLE IF EXISTS `ugo_chat_faculty_faculty`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_chat_faculty_faculty` (
  `chatid_ff` varchar(20) NOT NULL,
  `faculty1_id` varchar(20) DEFAULT NULL,
  `faculty2_id` varchar(20) DEFAULT NULL,
  `faculty1_send` tinyint(1) DEFAULT NULL,
  `message` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`chatid_ff`),
  KEY `faculty1_id` (`faculty1_id`),
  KEY `faculty2_id` (`faculty2_id`),
  CONSTRAINT `ugo_chat_faculty_faculty_ibfk_1` FOREIGN KEY (`faculty1_id`) REFERENCES `ugo_faculty` (`fid`),
  CONSTRAINT `ugo_chat_faculty_faculty_ibfk_2` FOREIGN KEY (`faculty2_id`) REFERENCES `ugo_faculty` (`fid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_chat_faculty_faculty`
--

LOCK TABLES `ugo_chat_faculty_faculty` WRITE;
/*!40000 ALTER TABLE `ugo_chat_faculty_faculty` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_chat_faculty_faculty` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ugo_chat_faculty_student`
--

DROP TABLE IF EXISTS `ugo_chat_faculty_student`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_chat_faculty_student` (
  `chatid_fs` varchar(20) NOT NULL,
  `faculty_id` varchar(20) DEFAULT NULL,
  `student_id` varchar(20) DEFAULT NULL,
  `faculty_send` tinyint(1) DEFAULT NULL,
  `message` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`chatid_fs`),
  KEY `faculty_id` (`faculty_id`),
  KEY `student_id` (`student_id`),
  CONSTRAINT `ugo_chat_faculty_student_ibfk_1` FOREIGN KEY (`faculty_id`) REFERENCES `ugo_faculty` (`fid`),
  CONSTRAINT `ugo_chat_faculty_student_ibfk_2` FOREIGN KEY (`student_id`) REFERENCES `ugo_student` (`sid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_chat_faculty_student`
--

LOCK TABLES `ugo_chat_faculty_student` WRITE;
/*!40000 ALTER TABLE `ugo_chat_faculty_student` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_chat_faculty_student` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ugo_continuous_eval`
--

DROP TABLE IF EXISTS `ugo_continuous_eval`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_continuous_eval` (
  `ceid` int(11) NOT NULL,
  `coid` varchar(20) DEFAULT NULL,
`activity_desc` varchar(20) DEFAULT NULL,  
`actid` int(11) DEFAULT NULL,
  
  `max_mark` double DEFAULT NULL,
  PRIMARY KEY (`ceid`),
  KEY `coid` (`coid`),
  KEY `actid` (`actid`),
  CONSTRAINT `ugo_continuous_eval_ibfk_1` FOREIGN KEY (`coid`) REFERENCES `ugo_course_offering` (`coid`),
  CONSTRAINT `ugo_continuous_eval_ibfk_2` FOREIGN KEY (`actid`) REFERENCES `ugo_activity_type` (`actid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_continuous_eval`
--

LOCK TABLES `ugo_continuous_eval` WRITE;
/*!40000 ALTER TABLE `ugo_continuous_eval` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_continuous_eval` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ugo_course_faculty_allocation`
--

DROP TABLE IF EXISTS `ugo_course_faculty_allocation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_course_faculty_allocation` (
  `fid` varchar(20) DEFAULT NULL,
  `cOid` varchar(20) DEFAULT NULL,
  `cfaid` int(11) NOT NULL,
  PRIMARY KEY (`cfaid`),
  KEY `fid` (`fid`),
  KEY `cOid` (`cOid`),
  CONSTRAINT `ugo_course_faculty_allocation_ibfk_1` FOREIGN KEY (`fid`) REFERENCES `ugo_faculty` (`fid`),
  CONSTRAINT `ugo_course_faculty_allocation_ibfk_2` FOREIGN KEY (`cOid`) REFERENCES `ugo_course_offering` (`coid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_course_faculty_allocation`
--

LOCK TABLES `ugo_course_faculty_allocation` WRITE;
/*!40000 ALTER TABLE `ugo_course_faculty_allocation` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_course_faculty_allocation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ugo_course_master`
--

DROP TABLE IF EXISTS `ugo_course_master`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_course_master` (
  `cid` varchar(20) NOT NULL,
  `course_name` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`cid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_course_master`
--

LOCK TABLES `ugo_course_master` WRITE;
/*!40000 ALTER TABLE `ugo_course_master` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_course_master` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ugo_course_offering`
--

DROP TABLE IF EXISTS `ugo_course_offering`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_course_offering` (
  `coid` varchar(20) NOT NULL,
  `cid` varchar(20) DEFAULT NULL,
  `semester` int(11) DEFAULT NULL,
  `sem_start` date DEFAULT NULL,
  `sem_end` date DEFAULT NULL,
  `sem_type` varchar(20) DEFAULT NULL,
  `batch` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`coid`),
  KEY `cid` (`cid`),
  CONSTRAINT `ugo_course_offering_ibfk_1` FOREIGN KEY (`cid`) REFERENCES `ugo_course_master` (`cid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_course_offering`
--

LOCK TABLES `ugo_course_offering` WRITE;
/*!40000 ALTER TABLE `ugo_course_offering` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_course_offering` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ugo_course_plan`
--

DROP TABLE IF EXISTS `ugo_course_plan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_course_plan` (
  `cpid` int(11) NOT NULL,
  `coid` varchar(20) DEFAULT NULL,
  `fp_weightage` int(11) DEFAULT NULL,
  `sp_weightage` int(11) DEFAULT NULL,
  `continuous_weightage` int(11) DEFAULT NULL,
  `end_sem_weightage` int(11) DEFAULT NULL,
  PRIMARY KEY (`cpid`),
  KEY `coid` (`coid`),
  CONSTRAINT `ugo_course_plan_ibfk_1` FOREIGN KEY (`coid`) REFERENCES `ugo_course_offering` (`coid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_course_plan`
--

LOCK TABLES `ugo_course_plan` WRITE;
/*!40000 ALTER TABLE `ugo_course_plan` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_course_plan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ugo_course_student_enrollment`
--

DROP TABLE IF EXISTS `ugo_course_student_enrollment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_course_student_enrollment` (
  `sid` varchar(20) DEFAULT NULL,
  `coid` varchar(20) DEFAULT NULL,
  `cseid` int(11) NOT NULL,
  PRIMARY KEY (`cseid`),
  KEY `sid` (`sid`),
  KEY `coid` (`coid`),
  CONSTRAINT `ugo_course_student_enrollment_ibfk_1` FOREIGN KEY (`sid`) REFERENCES `ugo_student` (`sid`),
  CONSTRAINT `ugo_course_student_enrollment_ibfk_2` FOREIGN KEY (`coid`) REFERENCES `ugo_course_offering` (`coid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_course_student_enrollment`
--

LOCK TABLES `ugo_course_student_enrollment` WRITE;
/*!40000 ALTER TABLE `ugo_course_student_enrollment` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_course_student_enrollment` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ugo_faculty`
--

DROP TABLE IF EXISTS `ugo_faculty`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_faculty` (
  `fid` varchar(20) NOT NULL,
  `faculty_name` varchar(50) DEFAULT NULL,
  `faculty_contact_no` varchar(20) DEFAULT NULL,
  `faculty_email` varchar(20) DEFAULT NULL,
  `faculty_device_id` varchar(20) DEFAULT NULL,
  `roleid` int(11) DEFAULT NULL,
  PRIMARY KEY (`fid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_faculty`
--

LOCK TABLES `ugo_faculty` WRITE;
/*!40000 ALTER TABLE `ugo_faculty` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_faculty` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ugo_faculty_role_mapping`
--

DROP TABLE IF EXISTS `ugo_faculty_role_mapping`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_faculty_role_mapping` (
  `ufrid` int(11) NOT NULL,
  `fid` varchar(20) DEFAULT NULL,
  `roleid` int(11) DEFAULT NULL,
  PRIMARY KEY (`ufrid`),
  KEY `roleid` (`roleid`),
  KEY `fid` (`fid`),
  CONSTRAINT `ugo_faculty_role_mapping_ibfk_1` FOREIGN KEY (`roleid`) REFERENCES `ugo_role_type` (`roleid`),
  CONSTRAINT `ugo_faculty_role_mapping_ibfk_2` FOREIGN KEY (`fid`) REFERENCES `ugo_faculty` (`fid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_faculty_role_mapping`
--

LOCK TABLES `ugo_faculty_role_mapping` WRITE;
/*!40000 ALTER TABLE `ugo_faculty_role_mapping` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_faculty_role_mapping` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ugo_leave_type`
--

DROP TABLE IF EXISTS `ugo_leave_type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_leave_type` (
  `ltd` int(11) NOT NULL,
  `leave_description` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`ltd`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_leave_type`
--

LOCK TABLES `ugo_leave_type` WRITE;
/*!40000 ALTER TABLE `ugo_leave_type` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_leave_type` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ugo_notification_faculty`
--

DROP TABLE IF EXISTS `ugo_notification_faculty`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_notification_faculty` (
  `fid` varchar(20) DEFAULT NULL,
  `nid` int(11) DEFAULT NULL,
  KEY `fid` (`fid`),
  KEY `nid` (`nid`),
  CONSTRAINT `ugo_notification_faculty_ibfk_1` FOREIGN KEY (`fid`) REFERENCES `ugo_faculty` (`fid`),
  CONSTRAINT `ugo_notification_faculty_ibfk_2` FOREIGN KEY (`nid`) REFERENCES `ugo_notifications` (`nid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_notification_faculty`
--

LOCK TABLES `ugo_notification_faculty` WRITE;
/*!40000 ALTER TABLE `ugo_notification_faculty` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_notification_faculty` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ugo_notification_student`
--

DROP TABLE IF EXISTS `ugo_notification_student`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_notification_student` (
  `sid` varchar(20) DEFAULT NULL,
  `nid` int(11) DEFAULT NULL,
  KEY `sid` (`sid`),
  KEY `nid` (`nid`),
  CONSTRAINT `ugo_notification_student_ibfk_1` FOREIGN KEY (`sid`) REFERENCES `ugo_student` (`sid`),
  CONSTRAINT `ugo_notification_student_ibfk_2` FOREIGN KEY (`nid`) REFERENCES `ugo_notifications` (`nid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_notification_student`
--

LOCK TABLES `ugo_notification_student` WRITE;
/*!40000 ALTER TABLE `ugo_notification_student` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_notification_student` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ugo_notifications`
--

DROP TABLE IF EXISTS `ugo_notifications`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_notifications` (
  `nid` int(11) NOT NULL,
  `message` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`nid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_notifications`
--

LOCK TABLES `ugo_notifications` WRITE;
/*!40000 ALTER TABLE `ugo_notifications` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_notifications` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ugo_role_type`
--

DROP TABLE IF EXISTS `ugo_role_type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_role_type` (
  `roleid` int(11) NOT NULL,
  `role_type` int(11) DEFAULT NULL,
  `role_desc` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`roleid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_role_type`
--

LOCK TABLES `ugo_role_type` WRITE;
/*!40000 ALTER TABLE `ugo_role_type` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_role_type` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ugo_student`
--

DROP TABLE IF EXISTS `ugo_student`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_student` (
  `sid` varchar(20) NOT NULL,
  `student_name` varchar(50) DEFAULT NULL,
  `student_contact_no` int(11) DEFAULT NULL,
  `student_email` varchar(20) DEFAULT NULL,
  `student_device_id` varchar(20) DEFAULT NULL,
  `counselorid` varchar(20) DEFAULT NULL,
  `advisorid` varchar(20) DEFAULT NULL,
  `batch` int(4) DEFAULT NULL,
  `section` varchar(4) DEFAULT NULL,
  PRIMARY KEY (`sid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_student`
--

LOCK TABLES `ugo_student` WRITE;
/*!40000 ALTER TABLE `ugo_student` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_student` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ugo_student_achievement`
--

DROP TABLE IF EXISTS `ugo_student_achievement`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_student_achievement` (
  `said` int(11) NOT NULL,
  `sid` varchar(20) DEFAULT NULL,
  `event` varchar(20) DEFAULT NULL,
  `date` date DEFAULT NULL,
  `duration` int(10) DEFAULT NULL,
  `remarks` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`said`),
  KEY `sid` (`sid`),
  CONSTRAINT `ugo_student_achievement_ibfk_1` FOREIGN KEY (`sid`) REFERENCES `ugo_student` (`sid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_student_achievement`
--

LOCK TABLES `ugo_student_achievement` WRITE;
/*!40000 ALTER TABLE `ugo_student_achievement` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_student_achievement` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ugo_student_continuous_eval`
--

DROP TABLE IF EXISTS `ugo_student_continuous_eval`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_student_continuous_eval` (
  `sceid` int(11) NOT NULL,
  `sid` varchar(20) DEFAULT NULL,
  `ceid` int(11) DEFAULT NULL,
  `mark` double DEFAULT NULL,
  PRIMARY KEY (`sceid`),
  KEY `sid` (`sid`),
  KEY `ceid` (`ceid`),
  CONSTRAINT `ugo_student_continuous_eval_ibfk_1` FOREIGN KEY (`sid`) REFERENCES `ugo_student` (`sid`),
  CONSTRAINT `ugo_student_continuous_eval_ibfk_2` FOREIGN KEY (`ceid`) REFERENCES `ugo_continuous_eval` (`ceid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_student_continuous_eval`
--

LOCK TABLES `ugo_student_continuous_eval` WRITE;
/*!40000 ALTER TABLE `ugo_student_continuous_eval` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_student_continuous_eval` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ugo_student_disciplinary`
--

DROP TABLE IF EXISTS `ugo_student_disciplinary`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_student_disciplinary` (
  `sdid` int(11) NOT NULL,
  `sid` varchar(20) DEFAULT NULL,
  `event` varchar(20) DEFAULT NULL,
  `date` date DEFAULT NULL,
  `duration` int(10) DEFAULT NULL,
  `remarks` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`sdid`),
  KEY `sid` (`sid`),
  CONSTRAINT `ugo_student_disciplinary_ibfk_1` FOREIGN KEY (`sid`) REFERENCES `ugo_student` (`sid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_student_disciplinary`
--

LOCK TABLES `ugo_student_disciplinary` WRITE;
/*!40000 ALTER TABLE `ugo_student_disciplinary` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_student_disciplinary` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ugo_student_leave`
--

DROP TABLE IF EXISTS `ugo_student_leave`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_student_leave` (
  `lid` int(11) NOT NULL,
  `sid` varchar(20) DEFAULT NULL,
  `ltd` int(11) DEFAULT NULL,
  `leave_from` date DEFAULT NULL,
  `leave_to` date DEFAULT NULL,
  PRIMARY KEY (`lid`),
  KEY `sid` (`sid`),
  KEY `ltd` (`ltd`),
  CONSTRAINT `ugo_student_leave_ibfk_1` FOREIGN KEY (`sid`) REFERENCES `ugo_student` (`sid`),
  CONSTRAINT `ugo_student_leave_ibfk_2` FOREIGN KEY (`ltd`) REFERENCES `ugo_leave_type` (`ltd`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_student_leave`
--

LOCK TABLES `ugo_student_leave` WRITE;
/*!40000 ALTER TABLE `ugo_student_leave` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_student_leave` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ugo_student_mark`
--

DROP TABLE IF EXISTS `ugo_student_mark`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_student_mark` (
  `smid` int(11) NOT NULL,
  `sid` varchar(20) DEFAULT NULL,
  `coid` varchar(20) DEFAULT NULL,
  `fp_mark` double DEFAULT NULL,
  `sp_mark` double DEFAULT NULL,
  `continuous_mark` double DEFAULT NULL,
  `end_sem_mark` double DEFAULT NULL,
  `grade` varchar(2) DEFAULT NULL,
  PRIMARY KEY (`smid`),
  KEY `sid` (`sid`),
  KEY `coid` (`coid`),
  CONSTRAINT `ugo_student_mark_ibfk_1` FOREIGN KEY (`sid`) REFERENCES `ugo_student` (`sid`),
  CONSTRAINT `ugo_student_mark_ibfk_2` FOREIGN KEY (`coid`) REFERENCES `ugo_course_offering` (`coid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_student_mark`
--

LOCK TABLES `ugo_student_mark` WRITE;
/*!40000 ALTER TABLE `ugo_student_mark` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_student_mark` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ugo_timetable`
--

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2017-03-17  9:57:16



