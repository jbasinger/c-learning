THE FORMAT
The format definition is as follows. You can use the libnetpbm C subroutine library to read and interpret the format conveniently and accurately.

A PPM file consists of a sequence of one or more PPM images. There are no data, delimiters, or padding before, after, or between images.

Each PPM image consists of the following:

A "magic number" for identifying the file type. A ppm image's magic number is the two characters "P6".
Whitespace (blanks, TABs, CRs, LFs).
A width, formatted as ASCII characters in decimal.
Whitespace.
A height, again in ASCII decimal.
Whitespace.
The maximum color value (Maxval), again in ASCII decimal. Must be less than 65536 and more than zero.
A single whitespace character (usually a newline).
A raster of Height rows, in order from top to bottom. Each row consists of Width pixels, in order from left to right. Each pixel is a triplet of red, green, and blue samples, in that order. Each sample is represented in pure binary by either 1 or 2 bytes. If the Maxval is less than 256, it is 1 byte. Otherwise, it is 2 bytes. The most significant byte is first.
A row of an image is horizontal. A column is vertical. The pixels in the image are square and contiguous.

In the raster, the sample values are "nonlinear." They are proportional to the intensity of the ITU-R Recommendation BT.709 red, green, and blue in the pixel, adjusted by the BT.709 gamma transfer function. (That transfer function specifies a gamma number of 2.2 and has a linear section for small intensities). A value of Maxval for all three samples represents CIE D65 white and the most intense color in the color universe of which the image is part (the color universe is all the colors in all images to which this image might be compared).

BT.709's range of channel values (16-240) is irrelevant to PPM.

ITU-R Recommendation BT.709 is a renaming of the former CCIR Recommendation 709. When CCIR was absorbed into its parent organization, the ITU, ca. 2000, the standard was renamed. This document once referred to the standard as CIE Rec. 709, but it isn't clear now that CIE ever sponsored such a standard.

Note that another popular color space is the newer sRGB. A common variation from PPM is to substitute this color space for the one specified. You can use pnmgamma to convert between this variation and true PPM.

Note that a common variation from the PPM format is to have the sample values be "linear," i.e. as specified above except without the gamma adjustment. pnmgamma takes such a PPM variant as input and produces a true PPM as output.

Minimal Subset
The PPM format is so simple that many programmers write programs to process it directly, without using a library such as libnetpbm, reverse engineering a subset of the format from examples rather than using the specification. Therefore, if you want to produce an image that as many programs as possible can read, you should stick to the following subset.

The image consists of the following bytes:

"P6" followed by newline
width and height separated by a space (e.g. "50 100"), followed by newline
maxval, followed by newline. At most 255; even more minimally, 255 exactly.
The raster
There is only one image in the file.

The program pnmtopnm produces this minimal subset, so if you have a more complex PGM image, you can pass it to to a less tolerant program through pnmtopnm. pamdepth can make the maxval 255.

Plain PPM
There is actually another version of the PPM format that is fairly rare: "plain" PPM format. The format above, which generally considered the normal one, is known as the "raw" PPM format. See pbm for some commentary on how plain and raw formats relate to one another and how to use them.

The difference in the plain format is:

There is exactly one image in a file.
The magic number is P3 instead of P6.
Each sample in the raster is represented as an ASCII decimal number (of arbitrary size).
Each sample in the raster has white space before and after it. There must be at least one character of white space between any two samples, but there is no maximum. There is no particular separation of one pixel from another -- just the required separation between the blue sample of one pixel from the red sample of the next pixel.
No line should be longer than 70 characters.
Here is an example of a small image in this format.

P3
# feep.ppm
4 4
15
 0  0  0    0  0  0    0  0  0   15  0 15
 0  0  0    0 15  7    0  0  0    0  0  0
 0  0  0    0  0  0    0 15  7    0  0  0
15  0 15    0  0  0    0  0  0    0  0  0
There is a newline character at the end of each of these lines.

Programs that read this format should be as lenient as possible, accepting anything that looks remotely like a PPM image.
