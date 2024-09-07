# vim:tabstop=2 softtabstop=2 shiftwidth=2 colorcolumn=80 autoindent expandtab

{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  packages = [ pkgs.cmake pkgs.SDL2 ];
}
