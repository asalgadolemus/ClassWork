import javafx.animation.Timeline;
import javafx.animation.KeyFrame;
import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.scene.text.Text;
import javafx.scene.transform.Scale;
import javafx.stage.Stage;
import javafx.util.Duration;

import java.util.Calendar;
import java.util.GregorianCalendar;

public class ControlAClock extends Application {

	@Override
	public void start(Stage primaryStage) throws Exception {
		DetailedClockPane clockPane = new DetailedClockPane();
		clockPane.start();
		Button btStart = new Button("Start");
		btStart.setOnAction(e -> clockPane.start());
		Button btStop = new Button("Stop");
		btStop.setOnAction(e -> clockPane.stop());

		HBox hBox = new HBox(btStart, btStop);
		hBox.setSpacing(10);
		hBox.setPadding(new Insets(10, 10, 10, 10));
		hBox.setAlignment(Pos.CENTER);
		BorderPane borderPane = new BorderPane(clockPane, null, null, hBox, null);
		borderPane.autosize();
		Scene scene = new Scene(borderPane);
		primaryStage.setScene(scene);
		primaryStage.setTitle("ControlAClock");
		primaryStage.show();


	}

	public static void main(String[] args) {
		Application.launch(args);
	}

	class DetailedClockPane extends Pane {
		private int hour;
		private int minute;
		private int second;
		private Timeline animation;

		// Clock pane's width and height

		private double w = 250, h = 250;

		/**
		 * Construct a default clock with the current time
		 */

		public DetailedClockPane() {
			setCurrentTime();
			animation = new Timeline(
					new KeyFrame(Duration.millis(1000), e -> moveClock()));
			animation.setCycleCount(Timeline.INDEFINITE);
			animation.play();
		}

		/**
		 * Construct a clock with specified hour, minute, and second
		 */

		public DetailedClockPane(int hour, int minute, int second) {
			this.hour = hour;
			this.minute = minute;
			this.second = second;
			paintClock();
			animation = new Timeline(
					new KeyFrame(Duration.millis(1000), e -> moveClock()));
			animation.setCycleCount(Timeline.INDEFINITE);
			animation.play();
		}

		/**
		 * Return hour
		 */

		public int getHour() {
			return hour;
		}

		/**
		 * Set a new hour
		 */
		public void setHour(int hour) {
			this.hour = hour;
			paintClock();
		}

		/**
		 * Return minute
		 */
		public int getMinute() {
			return minute;
		}

		/**
		 * Set a new minute
		 */
		public void setMinute(int minute) {
			this.minute = minute;
			paintClock();
		}

		/**
		 * Return second
		 */
		public int getSecond() {
			return second;
		}

		/**
		 * Set a new second
		 */
		public void setSecond(int second) {
			this.second = second;
			paintClock();
		}

		/**
		 * Return clock pane's width
		 */
		public double getW() {
			return w;
		}

		/**
		 * Set clock pane's width
		 */
		public void setW(double w) {
			this.w = w;
			paintClock();
		}

		/**
		 * Return clock pane's height
		 */
		public double getH() {
			return h;
		}

		/**
		 * Set clock pane's height
		 */
		public void setH(double h) {
			this.h = h;
			paintClock();
		}

		/* Set the current time for the clock */
		public void setCurrentTime() {
			// Construct a calendar for the current date and time
			Calendar calendar = new GregorianCalendar();
			// Set current hour, minute and second
			this.hour = calendar.get(Calendar.HOUR_OF_DAY);
			this.minute = calendar.get(Calendar.MINUTE);
			this.second = calendar.get(Calendar.SECOND);
			paintClock(); // Repaint the clock
		}

		/**
		 * Paint the clock
		 */
		private void paintClock() {

			// Initialize clock parameters
			double clockRadius = Math.min(w, h) * 0.8 * 0.5;
			double centerX = w / 2;
			double centerY = h / 2;

			// Draw circle
			Circle circle = new Circle(centerX, centerY, clockRadius);
			circle.setFill(Color.WHITE);
			circle.setStroke(Color.BLACK);

			// Draw second hand
			double sLength = clockRadius * 0.8;
			double secondX = centerX + sLength * Math.sin(second * (2 * Math.PI / 60));
			double secondY = centerY - sLength * Math.cos(second * (2 * Math.PI / 60));

			Line sLine = new Line(centerX, centerY, secondX, secondY);
			sLine.setStroke(Color.RED);

			// Draw minute hand
			double mLength = clockRadius * 0.65;
			double xMinute = centerX + mLength * Math.sin(minute * (2 * Math.PI / 60));
			double minuteY = centerY - mLength * Math.cos(minute * (2 * Math.PI / 60));
			Line mLine = new Line(centerX, centerY, xMinute, minuteY);
			mLine.setStroke(Color.BLUE);

			// Draw hour hand
			double hLength = clockRadius * 0.5;
			double hourX = centerX + hLength * Math.
					sin((hour % 12 + minute / 60.0) * (2 * Math.PI / 12));
			double hourY = centerY - hLength * Math.cos((hour % 12 + minute / 60.0) * (2 * Math.PI / 12));
			Line hLine = new Line(centerX, centerY, hourX, hourY);
			hLine.setStroke(Color.GREEN);
			getChildren().clear();
			getChildren().addAll(circle, sLine, mLine, hLine);

			// Display more details on the clock

			for (double i = 0; i < 60; i++) {

				double percent;

				if (i % 5 == 0) {

					percent = 0.9;

				} else {

					percent = 0.95;

				}

				double xOuter = centerX + clockRadius * Math.sin(i * (2 * Math.PI / 60));
				double yOuter = centerY - clockRadius * Math.cos(i * (2 * Math.PI / 60));
				double xInner = centerX + percent * clockRadius * Math.sin(i * (2 * Math.PI / 60));
				double yInner = centerY - percent * clockRadius * Math.cos(i * (2 * Math.PI / 60));
				getChildren().add(new Line(xOuter, yOuter, xInner, yInner));

			}// Display hours on the clock

			for (int i = 0; i < 12; i++) {
				double x = centerX + 0.8 * clockRadius * Math.sin(i * (2 * Math.PI / 12));
				double y = centerY - 0.8 * clockRadius * Math.cos(i * (2 * Math.PI / 12));
				Text text = new Text(x - 4, y + 4, "" + ((i == 0) ? 12 : i));getChildren().add(text);
			}
		}


		protected void moveClock() {
			if (minute == 60) {
				hour += 1;
			}
			if (second == 60) {
				minute += 1;
			}
			second = (second < 60 ? second + 1 : 1);
			paintClock();
		}

		//Method to start animation

		public void start() {
			animation.play();
		}

		//Method to stop animation

		public void stop() {
			animation.pause();
		}

	}
}