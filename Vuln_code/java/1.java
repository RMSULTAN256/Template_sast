import javax.servlet.http.*;

public class LoginServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) {
        HttpSession session = request.getSession();
        session.setAttribute("user", "admin");
        // No timeout set; session persists until server restart
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) {
        HttpSession session = request.getSession(false);
        if (session != null && request.getParameter("logout") != null) {
            session.removeAttribute("user");
        }
    }
}