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
  `actid` int(11) DEFAULT NULL,
  `activity_desc` varchar(20) DEFAULT NULL,
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
INSERT INTO `ugo_faculty` VALUES ('AM.FAC.CSE0001','Dr Sajeev. G.P',NULL,NULL,NULL,NULL),('AM.FAC.CSE0002','Dr Jyothisha J Nair',NULL,NULL,NULL,NULL),('AM.FAC.CSE0003','Dr Bhadrachalam Chitturi',NULL,NULL,NULL,NULL),('AM.FAC.CSE0004','Dr Swaminathan J',NULL,NULL,NULL,NULL),('AM.FAC.CSE0005','Dr R. Sreekumar',NULL,NULL,NULL,NULL),('AM.FAC.CSE0006','Ms Padmamala Sriram',NULL,NULL,NULL,NULL),('AM.FAC.CSE0007','Ms Sandhya Harikumar',NULL,NULL,NULL,NULL),('AM.FAC.CSE0008','Ms Remya R',NULL,NULL,NULL,NULL),('AM.FAC.CSE0009','Ms Jasmine. T. Bhaskar',NULL,NULL,NULL,NULL),('AM.FAC.CSE0010','Mr Sumesh K J',NULL,NULL,NULL,NULL),('AM.FAC.CSE0011','Ms Siji Rani S',NULL,NULL,NULL,NULL),('AM.FAC.CSE0012','Mr Sarath S',NULL,NULL,NULL,NULL),('AM.FAC.CSE0013','Ms Jayasree Narayanan',NULL,NULL,NULL,NULL),('AM.FAC.CSE0014','Ms Lekshmi S Nair',NULL,NULL,NULL,NULL),('AM.FAC.CSE0015','Ms Simi S',NULL,NULL,NULL,NULL),('AM.FAC.CSE0016','Ms Asha Asok',NULL,NULL,NULL,NULL),('AM.FAC.CSE0017','Ms Greeshma Sarath',NULL,NULL,NULL,NULL),('AM.FAC.CSE0018','Ms Thara S',NULL,NULL,NULL,NULL),('AM.FAC.CSE0019','Ms Archanan K Rajan',NULL,NULL,NULL,NULL),('AM.FAC.CSE0020','Ms Lekha S Nair',NULL,NULL,NULL,NULL),('AM.FAC.CSE0021','Ms Prathibhamol C P',NULL,NULL,NULL,NULL),('AM.FAC.CSE0022','Ms Geetha M',NULL,NULL,NULL,NULL),('AM.FAC.CSE0023','Ms Vinitha Panicker. J',NULL,NULL,NULL,NULL),('AM.FAC.CSE0024','Br Krishnaprasad',NULL,NULL,NULL,NULL),('AM.FAC.CSE0025','Ms Deepthi L.R',NULL,NULL,NULL,NULL),('AM.FAC.CSE0026','Ms Krishnaveni',NULL,NULL,NULL,NULL),('AM.FAC.CSE0027','Ms Gayathri R.G',NULL,NULL,NULL,NULL);
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
  PRIMARY KEY (`sid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_student`
--

LOCK TABLES `ugo_student` WRITE;
/*!40000 ALTER TABLE `ugo_student` DISABLE KEYS */;
INSERT INTO `ugo_student` VALUES ('AM.EN.H4CSE14002','Krithic P',NULL,NULL,NULL,NULL,NULL),('AM.EN.H4CSE14003','Priyanshu Das',NULL,NULL,NULL,NULL,NULL),('AM.EN.H4CSE14004','Sandeep Satheesh',NULL,NULL,NULL,NULL,NULL),('AM.EN.H4CSE14005','Balachander Srijith',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE12044','Subramonian R I',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE12123','Konda Abhijith Reddy',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE12128','Nandakumar G K',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE12503','Vishnu V',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE13134','Madhu V M',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE13148','Ranga Tarun Kumar',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14001','Atla Sowmya Reddy',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14003','Adarsh S',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14004','Aiswarya S',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14005','Akhil R',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14006','Akshay C V',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14007','Amrita Raghunath',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14008','Anagha R',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14009','Anand Sasikumar',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14010','Anumala Mrudula',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14011','Aparnna C G',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14012','Arjun P',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14014','Athira Sajimon Nair',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14015','Belede Rahul',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14017','Bommisetty Amar Rahul',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14018','Challa Manish Reddy',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14019','Chirath R',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14020','Devi Priya Madhusoodanan',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14021','Divya S Thankachy',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14022','Emmanuel C Baby',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14023','Gelle Tripura',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14024','Gayathri P Menakath',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14025','Gokul M S',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14028','H Chaithanya',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14029','Harigovind Thoyakkat',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14030','Haritha H',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14031','Heeraj',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14032','Indhu C',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14033','Jaliparthi Surya Prakash',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14034','K V S P Sai Sravya',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14035','Kandru Yateesh',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14036','Karthik Rajan',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14037','Kona Sravan Kumar Reddy',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14038','Kripa S Kumar',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14040','Kurapati Tharun',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14041','Kusu Manikanta Venkata Sai',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14042','Lakshmi P S',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14043','Sai Hari Chandan Morapakala',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14044','Mahendra Reddy Chagam',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14045','Mandapati Saikrishnareddy',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14047','Miryabelli Avinash',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14048','Mudunuri Phani Sanjay Varma',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14049','Nandakishor Prabhu R',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14051','Pagidimarry Showrya',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14052','Panthati Jagadeesh',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14053','Petla Manikanta Sai Kumar',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14056','Ramgopal S',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14057','Ramya Ramesh',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14058','S Sudarsan',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14059','Sai Kaushik',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14061','Sarang Sanal',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14062','Shiv Krishna A',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14063','Sidharth N',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14064','Seemakurthi Bhargava Nikhil',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14065','Sri Nikitha K',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14066','Sruthi Menon V K',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14067','Subham Kumar Gupta',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14068','Surapaneni Sri Sai Tarun',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14069','Suryarjuna Gopakumar',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14071','Vaddireddy Sai Charith Reddy',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14072','Varnajyosula Venkata Audisesha',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14073','Vindula Sai Yashwanth',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14075','Yelamakuri Lokesh Reddy',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14076','Anjali Unnikrishnan',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14077','Resya Reghu',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14101','Ayyagari Swathvik Reddy',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14102','Adarsh K',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14103','Adithya K Moorthy',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14104','Ajay Menon',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14105','Akhil Sudheer',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14106','Akshay Krishna M P',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14107','Amrita Sanjay',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14109','Anand Sukumar J V',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14110','Anupam T G',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14111','Aravind R B',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14112','Arun Babu',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14113','Athira S',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14114','Athul Krishna',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14116','Bhavanam Venkata Subba Rami',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14117','Chilukuri Shanmuka Saisaran',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14118','Chethan Dev',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14119','D Anirudh',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14120','Devi R Krishnan',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14121','E G Nidheep',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14124','Gokul Krishna P',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14125','Gokulakrishnan S R',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14126','Goutham S',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14127','Gumduboina Seshu Babu',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14128','H Vinayak Nair',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14129','Harikrishna K J',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14131','Indeevar Madapakula',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14132','Inumella Chaitanya',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14133','Jayakrishna Menon V',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14134','Kandimalla Vishnuvardhan',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14135','Karicharla Srinidhi',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14137','Kondapi Chandrika',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14138','Krishnavajjala Krishna Samhitha',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14139','Kuppili Venkata Sai Harsha Vard',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14140','Kurup Abhishek Suresh',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14141','Lakshmi Niveditha Govindu',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14142','Lolla Sravani',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14143','Maddula Pavan Kumar Reddy',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14144','Malavika Vinod',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14145','Manduva Vinay Chowdary',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14146','Meghna Raj',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14147','Movva Supriya',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14148','Mullapudi Aseesh',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14149','Neetish M M',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14150','P Avinash',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14151','Pallavi M',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14152','Panuganti Shashank',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14153','Pranav I',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14154','Prata Surya Pavan Saketh',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14155','Puttagunta Srirupa',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14156','Ramineni Manideep',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14157','S Sidharth Shankar',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14158','Sadhu Sai Kaushal',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14159','Sai Sampath Vadapalli',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14160','Sannidhi Satya Venkata Krishna',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14161','Saurav Vinod',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14162','Sidharth M',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14163','Sreelakshmi Ajith',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14164','Sreerag Venugopal',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14165','Sriram S',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14166','Sruthy Murali',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14167','Sura Lakshmana Rao',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14168','Surapuram Akhil',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14169','Tatikonda Shanmukha Sai Praneet',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14170','Udit S Joshi',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14171','Vaisakh M S',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14172','Velagapudi Venkatesh',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14174','Yashwanth Veluri',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14501','Gayathri C Ajayan',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14502','Bethu Vara Lakshmi',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14503','Neha Naramsetty',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14504','Yarasani Sriharsha Reddy',NULL,NULL,NULL,NULL,NULL),('AM.EN.U4CSE14505','Ashwanth Unni',NULL,NULL,NULL,NULL,NULL);
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
  `e_date_begin` date DEFAULT NULL,
  `e_date_end` date DEFAULT NULL,
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
  `st_date` date DEFAULT NULL,
  `en_date` date DEFAULT NULL,
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

DROP TABLE IF EXISTS `ugo_timetable`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ugo_timetable` (
  `ttid` int(11) NOT NULL,
  `coid` varchar(20) DEFAULT NULL,
  `day` varchar(20) DEFAULT NULL,
  `period` int(11) DEFAULT NULL,
  PRIMARY KEY (`ttid`),
  KEY `coid` (`coid`),
  CONSTRAINT `ugo_timetable_ibfk_1` FOREIGN KEY (`coid`) REFERENCES `ugo_course_offering` (`coid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ugo_timetable`
--

LOCK TABLES `ugo_timetable` WRITE;
/*!40000 ALTER TABLE `ugo_timetable` DISABLE KEYS */;
/*!40000 ALTER TABLE `ugo_timetable` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2017-03-17  9:57:16
