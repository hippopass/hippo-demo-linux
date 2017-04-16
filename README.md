![HippoSecurity](media/logo_round.png)

# HippoSecurity Toolkit

HippoSecurity server-side demo project for Linux

## Prerequisite

Please contact HippoSecurity support to obtain your copy of the shared library:  `libhippo-linux-x86_64.so`, and copy the binary file into project root folder.

## Build and run the demo

Clone this repository, make and run the `demo` binary, it will display gCode and prompt for OTP input:

```
$ make
$ ./demo
Your gCode is: 1610
Please enter OTP:
```

Launch `hippo-demo-android` client App on your Android device, it will need to be activated and then waiting for `gCode`.

Enter the above `gCode` into Android client to generate OTP, and then enter the OTP back to Linux console:

```
$ make
$ ./demo
Your gCode is: 1610
Please enter OTP: 408360
Valid OTP.
```

It shows OTP has been validated successfully.

## Integration

Copy codes from `demo.c` to your project, remember to modify it to read `pinCode` from your Linux device.

```
int level = 0;
char *username = "admin";
char *pinCode = "D100L1E-1234";
```

This demo library supports level 0 and admin user only, so you can keep them unchanged.

## License

MIT © HippoSecurity
