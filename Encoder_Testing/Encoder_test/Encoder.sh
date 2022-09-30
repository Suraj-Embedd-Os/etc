#!/bin/bash

rm Encoder
rm EncoderNewWTH
gcc Encoder.c -o Encoder -lpthread

gcc EncoderNewWTH.c -o EncoderNewWTH


