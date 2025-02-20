# Stock Exchange Simulator

## Project Description

This project is a simple Stock Exchange Simulator written in C++ using the SFML (Simple and Fast Multimedia Library) for graphics and user interface. It simulates a basic stock market environment where users can observe stock price fluctuations, view an order book, and perform buy and sell transactions for a single asset. The application tracks user balance, asset holdings, and transaction history, providing a visual representation of basic stock market mechanics.

## Requirements

To build and run this project, you will need the following installed on your system:

*   **C++ Compiler:**
    *   **GCC/MinGW** (GNU Compiler Collection for Windows) - **Highly Recommended** for its stability and cross-platform capabilities. Recommended to install via MSYS2.
    *   **Visual Studio** (Community, Professional, or Enterprise editions) -  For Windows users preferring an IDE.  *Note: Building with Visual Studio might require some manual configuration and could be less straightforward compared to GCC/MinGW.*
*   **CMake (version 3.10 or later):**  A cross-platform build system generator used to manage the build process. Download from [cmake.org](https://cmake.org/download/).
*   **SFML (Simple and Fast Multimedia Library) version 2.5.1 or later:** A multimedia library providing graphics, windowing, and system functionalities. Download the appropriate version for your compiler from [sfml-dev.org](https://www.sfml-dev.org/download.php).

## Building the Project

This project is designed to be built using either GCC/MinGW with CMake (recommended) or Visual Studio. Choose the build method that best suits your development environment.

### Building with GCC/MinGW and CMake (Recommended)

1.  **Install Prerequisites:** Ensure you have the following installed and accessible in your system's PATH environment variable:
    *   **MSYS2 and MinGW-w64 (including GCC, G++, and Make):** MSYS2 is a software distribution and building platform for Windows. It provides a Unix-like environment and package manager (pacman). It is used to install MinGW-w64, which includes GCC (C Compiler), G++ (C++ Compiler), and Make (build tool).

        *   **Download MSYS2:** Download the MSYS2 installer appropriate for your system architecture (e.g., `msys2-x86_64-latest.exe` for 64-bit Windows) from the official MSYS2 website: [https://www.msys2.org/](https://www.msys2.org/)
        *   **Install MSYS2:** Run the installer and follow the on-screen instructions. Choose an installation directory (e.g., `C:\msys64`).
        *   **Update MSYS2 Packages:** After installation, open the **MSYS2 MinGW 64-bit shell** (or 32-bit, depending on your choice) from the Start Menu.  Run the following command to update the base MSYS2 packages:
            ```bash
            pacman -Syu
            ```
            Close the shell and reopen it (MSYS2 MinGW shell) again after the update.
        *   **Install MinGW-w64 Toolchain (GCC, G++, Make):** In the reopened MSYS2 MinGW shell, install the MinGW-w64 toolchain, which includes GCC, G++, Make, and other essential tools for C++ development with MinGW:
            ```bash
            pacman -S mingw-w64-x86_64-toolchain  # For 64-bit GCC/G++ (Recommended for 64-bit systems)
            # OR
            pacman -S mingw-w64-i686-toolchain   # For 32-bit GCC/G++ (For 32-bit systems)
            ```
            Choose the appropriate toolchain based on your system architecture. **For most modern systems, the 64-bit toolchain (`mingw-w64-x86_64-toolchain`) is recommended.**  Confirm the installation when prompted by typing `y` and pressing Enter.
        *   **Verify Installation:** After installation, you should be able to run `gcc --version`, `g++ --version`, and `make --version` in the **MSYS2 MinGW shell** and see version information for each tool, confirming they are correctly installed and in your PATH within the MSYS2 environment.

    *   **CMake:** Download and install CMake from [cmake.org](https://cmake.org/download/). Ensure CMake executable directory is added to your system's PATH environment variable (as described in the CMake installer instructions).

    *   **SFML for MinGW:** Download the SFML SDK specifically built for MinGW GCC (e.g., "SFML 2.5.1 Windows (MinGW)"). Extract the downloaded SFML archive to a directory of your choice (e.g., `C:\SFML-2.5.1-mingw`).

2.  **Make CMake Available in MSYS2 MinGW Shell:**
    *   **Problem:** CMake installed to your Windows system PATH is not automatically available in the MSYS2 MinGW shell.
    *   **Solution (Temporary):** In the **MSYS2 MinGW shell**, run the following command, replacing `C:/Program Files/CMake/bin` with your actual CMake installation directory (use forward slashes):
        ```bash
        export PATH="/c/Program Files/CMake/bin:$PATH"
        ```
        **Verify:** After this, `cmake --version` should now work in your **MSYS2 MinGW shell**.
    *   **Permanent Solution (Recommended):** To make this PATH change permanent, add the `export PATH` line to your MSYS2 profile file (e.g., `~/.bashrc` or `~/.bash_profile`).

3.  **Open MSYS2 MinGW Shell:** Launch the **MSYS2 MinGW 64-bit shell** (or 32-bit) from your Start Menu.

4.  **Navigate to the Project Directory:** In the MSYS2 shell, use the `cd` command to navigate to the root directory of your project (where `CMakeLists.txt` is located). For example:
    ```bash
    cd /c/Users/YourUsername/Desktop/test_repo/single-stock-exchange
    ```
    (Note: MSYS2 uses a Unix-like path structure, e.g., `C:` drive is accessed as `/c/`).

5.  **Create a Build Directory:** Create a separate `build` directory to keep build files organized and enter it:
    ```bash
    mkdir build
    cd build
    ```

6.  **Run CMake to Generate Build Files:** Use CMake to generate Makefiles for MinGW. Provide the path to your SFML installation using the `-DSFML_DIR` variable. Replace `"C:/path/to/SFML/cmake/SFML"` with the actual path to the `cmake/SFML` directory within your SFML SDK.
    ```bash
    cmake .. -G "MinGW Makefiles" -DSFML_DIR="C:/SFML-2.5.1-mingw/lib/cmake/SFML"
    ```
    **Important:**
    *   Ensure the path in `-DSFML_DIR` is correct and points to the directory containing `SFMLConfig.cmake` or `sfml-config.cmake` file within your SFML SDK.
    *   Use forward slashes `/` in paths, even on Windows.

7.  **Build the Project using Make:** Execute the `mingw32-make` command to compile the project:
    ```bash
    mingw32-make
    ```
    
8. After building with `mingw32-make`, to ensure the `GieldaApp.exe` executable runs correctly, you **must copy the following DLL files** from the `bin` folders of your SFML SDK and mingw64 into the `build` directory (where `GieldaApp.exe` is located):

*   `sfml-graphics-d-2.dll`
*   `sfml-system-d-2.dll`
*   `sfml-window-d-2.dll`
*   `libwinpthread-1.dll`
*   `libgcc_s_seh-1.dll`
*   `libstdc++-6.dll`

These DLL files are essential runtime dependencies for the application to launch and function properly.

9.  **Run the Application:** Run `GieldaApp.exe` by double-clicking it in the file explorer within the `build` directory.

### Building with Visual Studio (Potentially Less Stable)

**Building with Visual Studio might require more manual configuration and could be less straightforward. You may need to troubleshoot settings if you encounter issues.**

1.  **Open the Solution File:** Navigate to the project directory in your file explorer and open the `Giełda.sln` file. This will open the project in Visual Studio.

2.  **Configure SFML Project Properties (All Configurations & Platforms):**
    To properly link SFML with your Visual Studio project, you need to configure the project properties for **"All Configurations"** and **"All Platforms"** to ensure SFML is correctly set up for both Debug and Release builds, and for both x86 and x64 architectures if needed.

    *   **Open Project Properties:** In Visual Studio, right-click on the `Giełda` project in the Solution Explorer and select "Properties".
    *   **Configuration and Platform:** At the top of the "Property Pages" dialog, ensure that the "Configuration" dropdown is set to **"All Configurations"** and the "Platform" dropdown is set to **"All Platforms"**. This ensures that the settings apply to all build configurations (Debug, Release) and target platforms.

    *   **Include Directories (C/C++ -> General):**
        *   Navigate to **C/C++ -> General -> Additional Include Directories**.
        *   Add the path to the `include` directory of your SFML SDK. For example:
            ```
            C:\SFML-2.5.1\[include]
            ```
            **Replace `C:\SFML-2.5.1\[include]` with the actual path to your SFML `include` directory.**

    *   **Library Directories (Linker -> General):**
        *   Navigate to **Linker -> General -> Additional Library Directories**.
        *   Add the path to the `lib` directory of your SFML SDK. For example:
            ```
            C:\SFML-2.5.1\[lib]
            ```
            **Replace `C:\SFML-2.5.1\[lib]` with the actual path to your SFML `lib` directory.**

    *   **Additional Dependencies (Linker -> Input):**
        *   Navigate to **Linker -> Input -> Additional Dependencies**.
        *   Add the following list of `.lib` files. **This list is based on provided settings and includes both debug (`-d`) and release versions, as well as static (`-s`) and dynamic linking libraries. You might need to adjust this list depending on your specific SFML usage and build configuration (Debug/Release, Static/Dynamic Linking):**

            ```
            sfml-system-s-d.lib
            sfml-system-d.lib
            sfml-window-s-d.lib
            sfml-window-d.lib
            sfml-graphics-d.lib
            sfml-graphics-s-d.lib
            sfml-main-d.lib
            kernel32.lib
            user32.lib
            gdi32.lib
            winspool.lib
            comdlg32.lib
            advapi32.lib
            shell32.lib
            ole32.lib
            oleaut32.lib
            uuid.lib
            odbc32.lib
            odbccp32.lib
            opengl32.lib
            freetype.lib
            ```
            **Copy and paste this entire list into the "Additional Dependencies" field.**

            **Important Notes about Additional Dependencies:**
            *   **Debug vs. Release Libraries:** The list includes both debug (`-d` suffix) and release versions of SFML libraries. Ensure you are linking against the correct libraries for your build configuration (Debug or Release).
            *   **Static vs. Dynamic Linking (`-s` suffix):** The list also includes static (`-s` suffix) and dynamic linking versions. Choose the appropriate libraries based on whether you intend to link SFML statically or dynamically. If you are unsure, starting with dynamic linking (libraries without `-s` suffix, like `sfml-graphics-d.lib` and `sfml-graphics.lib`) is usually simpler for beginners.
            *   **Adjust if Necessary:** You may not need to include *all* these libraries.  You can adjust this list based on the specific SFML modules you are actually using in your project. However, the provided list is a comprehensive starting point.

    *   **Click "OK"** to save the project properties.

3.  **Select Build Configuration and Platform:** In Visual Studio, choose your desired build configuration (e.g., `Debug` or `Release`) and platform (e.g., `x64` or `x86`) from the dropdown menus in the toolbar.

4.  **Build the Solution:** Go to `Build` -> `Build Solution` (or press `Ctrl+Shift+B`).

5.  **Run the Application:** After successful build, run the application by going to `Debug` -> `Start Without Debugging` (or press `Ctrl+F5`). The executable `GieldaApp.exe` (or `Giełda.exe` if target name wasn't changed) will be created in the `x64/Debug` or `x64/Release` folder.  **If you encounter issues running from Visual Studio, ensure that SFML DLLs are copied to the executable directory (x64/Debug or x64/Release).**

## Embedded Font

The project is configured to embed the `arial.ttf` font directly into the executable. This means you **do not need to distribute the `arial.ttf` font file separately** with the application. The font data is included in the `arial_font_data.h` file and loaded from memory during runtime.

## Usage

Upon running the Stock Exchange Simulator:

*   **Price Chart:** The application displays a real-time line chart visualizing the stock price fluctuations over time.
*   **Order Book:** An order book section presents buy and sell offers, showing volumes and prices for both bid (buy) and ask (sell) orders.
*   **Buy/Sell Buttons:** Interactive "BUY" and "SELL" buttons allow users to initiate transactions.
*   **Transaction History:** A transaction history section logs the user's recent buy and sell actions.
*   **Balance Tracking:** The application tracks and displays the user's current balance, asset holdings, and portfolio change (profit/loss).
*   **Interaction:** Click the "BUY" or "SELL" buttons to activate transaction mode. Use the "+" and "-" indicators to adjust the transaction amount. Click "BUY" or "SELL" again to confirm the transaction (Buy only works if balance is sufficient).

The application also saves user data (wealth, amount, balance) and stock prices to a file named "Save" in the project directory when closed, and loads this data upon next startup, providing a basic persistence mechanism.

## License

This project is licensed under the MIT License.
