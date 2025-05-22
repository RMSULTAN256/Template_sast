# config/initializers/session_store.rb
Rails.application.config.session_store :cookie_store, key: '_my_app_session', expire_after: 1.year

# app/controllers/sessions_controller.rb
class SessionsController < Application_Controller
  def create
    session[:user_id] = User.find_by(email: params[:email]).id
    redirect_to dashboard_path
  end

  def destroy
    # Incorrect: Only clears session data, cookie persists
    session.delete(:user_id)
    redirect_to login_path
  end
end
