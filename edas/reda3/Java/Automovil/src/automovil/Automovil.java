/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package automovil;

/**
 *
 * @author mngomezz
 */
public class Automovil
{

    private static int kilometrajeTotal;
    private String marca;
    private String modelo;
    private int anio;
    private int kilometraje;

    Automovil(String marca, String modelo, int anio) {
        this.marca = marca;
        this.modelo = modelo;
        this.anio = anio;
    }

    public static int getKilometrajeTotal() {
        return Automovil.kilometrajeTotal;
    }

    public int getKilometraje() {
        return this.kilometraje;
    }

    public void recorre(int km) {
        this.kilometraje += km;
        Automovil.kilometrajeTotal += km;
    }

    @Override
    public String toString() {
        return "Automovil{" + "marca=" + marca + ", modelo=" + modelo
                + ", anio=" + anio + ", kilometraje=" + kilometraje + '}';
    }

}
