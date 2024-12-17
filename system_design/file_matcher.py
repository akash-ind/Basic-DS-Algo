class FileMatcher:   # We can use trie also for matching

    def __init__(self, folders: list, files: list) -> None:
        self.folders = folders
        self.files = files

    def get_path_separator(self):
        return "/"

    def match_folder_path(self, folder_path: str, path: str) -> bool:
        separator = self.get_path_separator()
        folder_path_list = folder_path.split(separator)

        file_path_list = path.split(separator)

        for i in range(len(folder_path_list)):
            if i >= len(file_path_list):
                return False

            if folder_path_list[i] != file_path_list[i]:
                return False

        return True

    def match_file_path(self, file_path, path) -> bool:
        return file_path == path

    def match_path(self, path: str) -> bool:
        for folder_path in self.folders:
            if self.match_folder_path(folder_path, path):
                return True
            
        for file_path in self.files:
            if self.match_file_path(file_path, path):
                return True
            
        return False


if __name__ == "__main__":
    f = FileMatcher(["/home/akash", "/home/krish"], ["/home/akash/file.txt", "/home/aka/dnd.txt"])

    print(f.match_path("/home/akash/nijvddfjin.txt"))
    print(f.match_path("/home/aka/dnd.txt"))
    print(f.match_path("/home/fnhf/jn.txt"))