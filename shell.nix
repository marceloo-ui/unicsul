{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  name = "unicsul-adventure-mode";

  buildInputs = [
    pkgs.gcc
    pkgs.gnumake
    pkgs.cowsay
    pkgs.fortune
    pkgs.figlet
  ];

  shellHook = ''
    echo "🧙 Welcome, traveler. Your coursework quests await."
    echo "Tip: save often, compile twice, segfault never."
  '';
}
