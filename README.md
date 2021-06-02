# pid-controller
 Cross-platform C library for PID controller and variants.

## Table of Contents
 1. Getting Started
    * About the Project
    * Replit Demo
    * Building the PID Controller Library
    * Running the Demo Application
 2. Library Guide
    * Overview
    * Proportional Controller
    * Integral Controller
    * Derivative Controller
    * Combining Controllers
    * Configuration
      * Dynamic Clamping
      * Variable Type
    * Build Sequence
 3. API Reference

## Getting Started

#### About the Project

 This project is a platform-independent library of various proportional,
 integral, and derivative controllers written in C, compatible with C++.
 The controllers in this project are object-oriented, written as C structures
 to store information such as gain variables, integral sum, and derivative
 error differences. Dynamic clamping of the output variable, and the type
 definition used in the control and gain variables, is configurable via the
 pid\_conf.h header file.

#### Replit Demo

 The demo application linked against the PID controller library is available
 on Replit. As of right now, the demo compiles with dynamic clamping configured
 to +/- 255, variable type to float, target value to 128, Kp to 0.1, Ki to 0.2,
 and Kd to 0.3. In future updates I will changes this to a user prompted scanf,
 I just haven't gotten around to it yet.

 [Replit Demo](https://replit.com/@bdreece/pid-controller)

#### Building the PID Controller Library

 The PID Controller Library can be easily compiled into shared and/or static
 libraries for any platform. First, be sure to have cloned the repository
 into your current working directory, and navigate to it:

 ```bash
 git clone https://github.com/bdreece/pid-controller.git && cd pid-controller/
 ```

 Next, you can review and configure the Makefile in your current directory.
 As you can see, the default build sequence compiles all the source files into
 object files, then links these objects together into static and dynamic
 libraries. The default build sequence also compiles and links a demo
 application against the PID Controller library. This demo can be used to
 manually test the behavior of manipulating gain variables. Future updates will
 include file input and output support for .csv files.

#### Running the Demo Application

 After you've built the libraries and demo application on your system, two new
 directories should appear: bin/ and lib/. The latter contains the compiled
 libraries, and the former, more importantly, contains the compiled binary of
 the demo application. This program can be run as follows:

 ```bash
 ./bin/pid_demo <TARGET> <KP> <KI> <KD>
 ```

 The application will continually prompt for the current measurement value to
 use in calculating the control variable. With each successive input, the
 control variable will change, attempting to bring the measurement value toward
 the target value (barring any wild gain configurations).

## Library Guide

- [ ] TODO: Write library guide

## API Reference

- [ ] TODO: Link Doxygen index on Github Pages
