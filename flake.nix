{
  description = "C and C++";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs =
    {
      self,
      nixpkgs,
      flake-utils,
      ...
    }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = import nixpkgs { inherit system; };
      in
      {
        devShell = pkgs.mkShell {
          shell = pkgs.zsh;
          shellHook = ''
            echo "Welcome to the Programmatic Playground flake dev shell" 

            # SSH keys to add (customize this list as needed)
            SSH_KEYS=(
              "$HOME/.ssh/gh_id_ed25519"
              "$HOME/.ssh/gt_id_ed"
            )

            # Start SSH agent if not already running
            if [ -z "$SSH_AUTH_SOCK" ]; then
              # Check if any keys exist before starting agent
              key_exists=false
              for key in "''${SSH_KEYS[@]}"; do
                if [ -f "$key" ]; then
                  key_exists=true
                  break
                fi
              done

              if [ "$key_exists" = true ]; then
                eval $(ssh-agent -s) > /dev/null
                # Add all existing keys
                for key in "''${SSH_KEYS[@]}"; do
                  if [ -f "$key" ]; then
                    ssh-add "$key" 2>/dev/null && echo "Added SSH key: $(basename $key)"
                  fi
                done
              fi
            fi
          '';

          # LLVM stuff
          # CPATH = builtins.concatStringsSep ":" [
          #   (lib.makeSearchPathOutput "dev" "include" [ llvm.libcxx ])
          #   (lib.makeSearchPath "resource-root/include" [ llvm.clang ])
          # ];
        };
      }
    );
}
