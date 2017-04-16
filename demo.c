/* Copyright (C) 2017 HippoSecurity */
#include <stdio.h>
#include "hippo.h"

int main() {

    char* apiKey = "623664303192b517e663f46f3314b7f3";

    // 1. initialize library
    int handle = hippo_init(apiKey);
    if (handle < 1) {
        printf("Invalid API Key!\n");
        return 1;
    }

    // 2. signup
    int level = 0;
    char *username = "admin";
    char *pinCode = "D100L1E-1234";

    hippo_signup(handle, level, username, pinCode);

    // 3. pre-Auth
    char gCode[4 + 1];
    int token = hippo_pre_auth(handle, gCode, 4);
    if (token < 1) {
        printf("Failed to generate gCode!\n");
        return 1;
    }
    printf("Your gCode is: %s\n", gCode);

    // 4. wait for OTP input
    char otp[64];
    printf("Please enter OTP: ");
    scanf("%s", otp);

    // 5. verify OTP
    int valid = hippo_verify_otp(handle, username, token, otp);

    // 6. close library
    hippo_done(handle);

    if (valid) {
        printf("Valid OTP.\n");
    } else {
        printf("Invalid OTP!\n");
    }
    return 0;
}
