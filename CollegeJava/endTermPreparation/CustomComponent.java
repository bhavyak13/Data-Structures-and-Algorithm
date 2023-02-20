import java.awt.*;

public class CustomComponent extends Component {
  private Color color;

  public CustomComponent(Color color) {
    this.color = color;
    setSize(100, 100);
  }

  @Override
  public void paint(Graphics g) {
    g.setColor(color);
    g.fillRect(0, 0, getWidth(), getHeight());
  }
}
