#!/bin/bash

ffmpeg -i imgs/frame-%04d.ppm -r 60 output.mp4

