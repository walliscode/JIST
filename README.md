# JIST

<!--toc:start-->

- [JIST](#jist)
  - [General Overview and motivations](#general-overview-and-motivations)
  - [Modules](#modules) - [models](#models) - [data](#data) - [logic](#logic) -
  [visualization](#visualization) - [terminal](#terminal) -
  [geographical](#geographical)
  <!--toc:end-->

JIST or just in time scheduling aims to be a comlete data driven system, for
taking in personnel information and providing various data presentations and
analysis tools to help with very fast and accurate scheduling of personnel.

## General Overview and motivations

Observation of manual scheduling of fire service personnel had me asking if
there was a computer driven solution that could react to he very recent changes
in personnel availability and provide a more accurate and efficient scheduling
solution. The goal of JIST is to provide a system that can take in personnel
information, such as availability, skills, and preferences, and generate
optimized schedules that meet the needs of the organization while also
considering the well-being of the personnel.

## Modules

The JIST system is composed of several modules that work together to provide the
solution. The goal is to have a few deep modules and this markdown should show
the layering within modules.

### models

This describes the core structure of the data and how it is stored and
manipulated. It includes the data models for everything that needs to be stored
and the relationships between them.

### data

The module that handles the data input and output. It includes the code for
reading data from various sources, data validation and finally conversion to the
internal data models.

### logic

The logic module where different algorithms and reasoning is applied to the data
to provide solutions.

### visualization

Data is presented in a read only format. Allowing for inspection of the data and
the results of the scheduling algorithms. This should consume the output from
the logic module.

#### terminal

A simple terminal output for the data. The primary goal is to provide something
simple to interact with to develop the data algorithms whilst the more user
friendly visualization module is being developed.

#### geographical

A dashboard that can provide easy status information. Such as red/green status
e.t.c. This will be linked to geographical data.
