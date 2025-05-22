import java.util.Scanner;
import java.util.logging.Logger;

public class LoginSystem {

    private static final Logger logger = Logger.getLogger(LoginSystem.class.getName());

    // Simulated database of users
    private static final String[][] users = {
        {"admin", "admin123"},
        {"user1", "pass123"},
        {"john", "doe123"}
    };

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("=== Welcome to the Login System ===");
        System.out.print("Enter username: ");
        String username = scanner.nextLine();  // ⚠️ User-controlled input

        System.out.print("Enter password: ");
        String password = scanner.nextLine();  // ⚠️ User-controlled input

        logLoginAttempt(username);  // ⚠️ CWE-117 vulnerability

        if (authenticate(username, password)) {
            System.out.println("✅ Login successful!");
            logger.info("User logged in successfully: " + username);  // ⚠️ Vulnerable logging
        } else {
            System.out.println("❌ Login failed!");
            logger.warning("Failed login attempt for user: " + username);  // ⚠️ Vulnerable logging
        }

        scanner.close();
    }

    private static boolean authenticate(String username, String password) {
        for (String[] user : users) {
            if (user[0].equals(username) && user[1].equals(password)) {
                return true;
            }
        }
        return false;
    }

    private static void logLoginAttempt(String username) {
        // ⚠️ Vulnerable to log injection if username includes \n or log-like entries
        logger.info("Login attempt by user: " + username);
    }
}
