# Word Search Puzzle Solver
Tugas Kecil 1 IF2211 Strategi Algoritma Semester II Tahun 2021/2022

Menyelesaikan Word Search Puzzle Dengan Menggunakan Algoritma Brute-Force 

## Table of Contents
* [General Information](#general-information)
* [Setup and Requirements](#setup-and-requirements)
* [Usage](#usage)
* [Contact](#contact)

## General Information
  Program sederhana yang ditulis dalam C ini memecahkan teka-teki pencarian kata dengan algoritma brute-force. Ini pertama kali membaca melalui input file teks yang diberikan yang berisi matriks teka-teki dan kata kunci untuk ditemukan. Kemudian, ia melintasi semua huruf teka-teki satu per satu. Jika huruf pertama benar, maka akan memeriksa semua 8 arah angin (Timur, Tenggara, Selatan, dll.) untuk semua huruf yang tersisa. Diselesaikan dengan algoritma exhaustice search yang akan memeriksa semua kemungkinan yang ada pada puzzle.

## Setup and Requirements
Program dapat dicompile di cmd ataupun di terminal teks editor seperti vs code dan akan menampilkan tampilan awal atau utama sebagai berikut
<img src="awal.jpg" />

A `.txt` file is used as the input for the puzzle and keywords. The file should follow the pattern
```
<PUZZLE>

<KEYWORDS>
```
with spaces separating each character of the puzzle. Between the puzzle there should be an empty line. An example is as follows
```
J S O L U T I S
S U N A R U U A
N E P T U N E T
S O N I E I S U
R C E V T R E R
A H T R A E S N
M M E R C U R Y

EARTH
JUPITER
MARS
MERCURY
NEPTUNE
SATURN
URANUS
VENUS
```
## Usage
Word search puzzle dapat dibuat sendiri pada link berikut ini <a href="https://randomwordgenerator.com/">random word generator</a> and <a href="https://tools.atozteacherstuff.com/word-search-maker/wordsearch.php">word search generator</a>.

## Contact
This program was made by Febryola Kurnia Putri (13520140).
email : 13520140@std.stei.itb.ac.id
