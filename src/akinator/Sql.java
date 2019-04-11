package akinator;

import java.sql.*;

public class Sql {

    private Connection cnn;
    private PreparedStatement ps;
    private ResultSet rs;

    public Sql() {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            cnn = DriverManager.getConnection("jdbc:mysql://localhost:3306/tree", "root", "raulito10");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void insert(String[] datos) {
        try {
            String sql = "INSERT INTO heroes (nombre,cualidades) VALUES (?,?)";
            ps = cnn.prepareStatement(sql);
            ps.setString(1, datos[0]);
            ps.setString(2, datos[1]);
            ps.executeUpdate();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public int getRows() {
        try {
            String sql = "SELECT * from heroes";
            ps = cnn.prepareStatement(sql);
            rs = ps.executeQuery();
            int n_rows = 0;
            while (rs.next()) {
                n_rows++;
            }
            return n_rows;
        } catch (Exception e) {
            e.printStackTrace();
        }
        return 0;
    }

    public String[][] getMatriz() {
        try {
            int n_rows = this.getRows();
            String sql = "SELECT nombre,cualidades from heroes";
            ps = cnn.prepareStatement(sql);
            rs = ps.executeQuery();
            String datosHeroes[][] = new String[n_rows][2];
            int row = 0;
            while (rs.next()) {
                datosHeroes[row][0] = rs.getString("nombre");
                datosHeroes[row++][1] = rs.getString("cualidades");
            }
            return datosHeroes;
        } catch (Exception e) {
            e.printStackTrace();
        }
        return new String[][]{{""}, {""}};
    }
}
