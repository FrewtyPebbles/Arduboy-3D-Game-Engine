Import("env")

import os
import json



# This loads the variables from .env.json
# expected environment variables are added via the `set_env_help_info` parameter in platformio.ini
# example:
# set_env_help_info =
#    ARDUINO_LIBS_PATH:"This should be set to the path to the game engine lib dependencies."
#    ABE_PATH:"This should be the path to your ProjectABE.exe arduboy emulator"
ERROR_PREFIX = "Failed to load environment variables:"
RED_COLOR_CODE = "\033[31m"
GREEN_COLOR_CODE = "\033[32m"
RESET_COLOR_CODE = "\033[0m"
try:
    with open(".env.json", "r") as fp:

        raw:str = env.GetProjectOption("set_env_help_info")
        expected_variables:dict[str, str] = {}

        if raw:
            for entry in raw.split("\n"):
                entry = entry.lstrip().rstrip()
                if entry == "":
                    continue
                key, value = entry.split(":")
                expected_variables[key] = value

        data:dict[str, str] = json.load(fp)


        for expected_var, info in expected_variables.items():
            if expected_var not in data:
                raise RuntimeError(f"expected {expected_var!r} env variable to be set in .env.json. Please set it now.\n{info}")

        for key, value in data.items():
            os.environ[key] = value

        print(f"{GREEN_COLOR_CODE}✅ Loaded environment variables from .env file.{RESET_COLOR_CODE}")
except RuntimeError as err:
    print(f"{RED_COLOR_CODE}{ERROR_PREFIX} {err.args[0]}{RESET_COLOR_CODE}")
    exit(1)
except FileNotFoundError as err:
    print(f"{RED_COLOR_CODE}{ERROR_PREFIX} a \".env.json\" file was not found in the current directory.  Please create one with the nessicary environment variables.{RESET_COLOR_CODE}")
    exit(1)