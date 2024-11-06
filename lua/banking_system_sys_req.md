# A simple banking system

## Introduction

This document contains system requirements for a simple banking system. It is intended to be used as an exercise (pet project) when learning a new programming language.

## General description

The banking system will work on a single computer. It will be implemented as a text interface. The information will be stored in plain text files. The following operations must be supported:
    
    + Add a new client

    + Remove a client

    + The client performs a money deposit

    + The client withdrawals money

    + List information about a client

    + List information about all clients

 The operations will be invoked from a text based menu. The data will be stored in plain text files. Information about client will be stored in *clients.txt* in the following form : id, first name, last name, birthday. Example: 121, John, Doe, 03.03.2002

 The information about client's money will be stored in other file named *money.txt*. And it has the following format : id, currency type, amount. Example: 121, eur, 2000. This means that the user with id 121 has 2000 eur in his account.

 During his work, the operator will see a screen with the following menu:

    'a' - Add a new client
    'r' - Remove a client
    'i' - Deposit
    'o' - Withdraw
    'p' - Print information about a client
    'l' - List information about all clients
    'b' - Balance
    'x' - Exit the system

## Detailed description of operations

### Add a new client

In order to invoke this operation, "a" key must be pressed ("a" from add). The following data will be collected : first name, last name, birthday. The information will be stored in a text file, the user will receive an ID which is unique in the system. The ID will be shown on the screen after the operation is completed.

### Remove a client

In order to invoke this operation "r" key must be pressed ("r" from remove). The operator will input user's id which is going to be removed.

### The client performs a money deposit

The operator will enter ID for the client, amount and currency type. The operation will be invoked by "i" key ("i" - input)

### The client performs a money withdrawal

The operator will enter ID for the client, amount and currency type. The operation will be invoked by "o" key ("o" - output)

### List information about a client

The operator will enter ID of the client. The information about this client (ID, first name, last name, birthday) will be shown on display. The operation will be invoked by "p" key ("p" - print)

### List information about all clients

The operator will use "l" key for this operation ("l" - list). By pressing on "l" key, he will the list of all clients, thir IDs, first name, last name, birthdays

### Balance

By pressing "b" key ("b" from balance), the operator will able to see how much money a specific client has in his account. The operator will enter ID of the client. On the screen he will see amounts and currency types

### Exit the system

By pressing "x" (from eXit) key the operator will exit from system

